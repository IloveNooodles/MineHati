#include "Inventory.hpp"

Inventory::Inventory() : Menu()
{
  this->capacity = 27;
  this->storage = new pair<Item *, string>[27];
  for (int i = 0; i < 27; i++)
  {
    this->storage[i] = make_pair(new Item(), "I" + to_string(i));
  }
}

Inventory::~Inventory()
{
  delete[] this->storage;
}


void Inventory::Discard(string Id, int quantity)
{
  if (quantity <= 0)
  {
    throw("non-positive integer");
  }
  int i = stoi(Id.substr(1));
  if (i < 0 || i > 26)
  {
    throw("Id tidak ditemukan");
  }
  if (this->storage[i].first->isTool() == true)
  {
    if (quantity > 1)
    {
      throw("Jumlah yang dibuang melebihi kuantitas");
    }
    this->storage[i] = make_pair(new Item(), this->storage[i].second);
  }
  if (quantity > this->storage[i].first->getQuantity())
  {
    throw("Jumlah yang dibuang melebihi kuantitas");
  }
  this->storage[i].first->addQuantity((-1) * quantity);
  if (this->storage[i].first->getQuantity() == 0)
  {
    this->storage[i] = make_pair(new Item(), this->storage[i].second);
  }
}

void Inventory::Use(string Id)
{
  int i = stoi(Id.substr(1));
  if (i < 0 || i > 26)
  {
    throw("Id tidak ditemukan");
  }
  if (this->storage[i].first->isTool() == false)
  {
    throw("Bukan tools");
  }
  this->storage[i].first->decreaseDurability(1);
  if (this->storage[i].first->getDurability() <= 0)
  {
    this->storage[i] = make_pair(new Item(), this->storage[i].second);
  }
}

void Inventory::MoveInventory(string src, string dest)
{
  int i = stoi(src.substr(1));
  int j = stoi(dest.substr(1));
  if (i < 0 || i > 26)
  {
    throw("Id tidak ditemukan");
  }
  if (j < 0 || j > 26)
  {
    throw("Id tidak ditemukan");
  }
  if (!this->storage[i].first->isNontool() && !this->storage[j].first->isNontool())
  {
    throw("Item yang ditumpuk bukan non-tools");
  }
  int sisa = 64 - this->storage[j].first->getQuantity();
  if (this->storage[i].first->getQuantity() <= sisa)
  {
    /* invMatrix[i][j] habis */
    this->storage[j].first->addQuantity(this->storage[i].first->getQuantity());
    this->storage[i] = make_pair(new Item(), this->storage[i].second);
  }
  else
  {
    this->storage[j].first->addQuantity(sisa);
    this->storage[i].first->addQuantity(-1 * sisa);
  }
}
void Inventory::Craft(ItemsReader& items, RecipesReader& recipes)
{
    vector<Recipe> r = recipes.getRecipes();
    bool recipeFound = false;
    /* Cek apakah tipe yang harus membenarkan atau tidak */
    bool fixedItem = false;
    int itemCount = 0; /* Banyak non tool */
    int itemDura[] = {-1, -1};
    string itemName[] = {"-", "-"};
    for (int i = 0; i < 9 && itemCount < 2; i ++) //ini yang memperbaiki tools
    {
        string name = this->craftingGrid[i].first->getName();
        if (name != "-")
        {
            if (items.getCtg(name) == "TOOL")
            {
                itemDura[itemCount] = this->craftingGrid[i].first->getDurability();
                itemName[itemCount] = this->craftingGrid[i].first->getName();
                itemCount ++;
            } 
            else
            {
                itemCount += 999; /* Agar keluar dari loop */
            }
        }
    }
    if (itemCount == 2)
    {
        if (itemName[0] == itemName[1])
        {
            /* Boleh melakukan fix */
            fixedItem = true;
        }
    }
    if (fixedItem)
    {
        /* Yang dilakukan adalah memperbaiki item */
        int dura = (itemDura[0] + itemDura[1] > 10 ? 10 : itemDura[0] + itemDura[1]);
        (items, itemName[0], 1, dura);
        give(items, itemName[0], 1, dura);
        EmptyCrafting();
    }
    else
    {
      for (int x = 0; x < r.size(); x ++)
      {
        vector<vector<string>> recipe = r[x].getRecipe();
        int rows = r[x].getRows();
        int cols = r[x].getCols();
        if (rows != getCraftingRows() || cols != getCraftingCols())
        {
          continue;
        }
        /* Looping pada matrix c */
        bool foundDifferent = false;
        for (int i = 0; i < 3 - rows + 1 && !recipeFound; i ++)
        {
          for (int j = 0; j < 3 - cols + 1 && !recipeFound; j ++)
          {
            foundDifferent = false;
            for (int k = 0; k < rows && !foundDifferent; k ++)
            {
              for (int l = 0; l < cols && !foundDifferent; l ++)
              {
                if (getElement(i + k, j + l).first->getName() != "-")
                {
                  string type = items.getType(getElement(i + k, j + l).first->getName());
                  if (type != "-") {
                    /* Ada tipenya */
                    foundDifferent = type != recipe[k][l];
                  } else {
                    /* Tidak ada tipenya */
                    foundDifferent = getElement(i + k, j + l).first->getName() != recipe[k][l];
                  }
                }
                else
                {
                  foundDifferent = getElement(i + k, j + l).first->getName() != recipe[k][l];
                }
              }
            }
            /* k dan l out of range atau foundDifferent = true */
            if (!foundDifferent)
            {
              recipeFound = true; 
            }
          }
        }

        if (recipeFound)
        {
            EmptyCrafting();
            give(items, r[x].getName(), r[x].getAmount());
        }
      }
    }
    if (!recipeFound && !fixedItem) 
    {
        throw("Gagal melakukan crafting");
    }
}
void Inventory::EmptyCrafting()
{
    for(int i = 0; i<craftingCapacity; i++)
    {
        if(this->craftingGrid[i].first->getName() != "-")
        {
            this->craftingGrid[i] = make_pair(new Item(),this->craftingGrid[i].second);
        }
    }
}
int Inventory::getCraftingRows()
{
  int minRow = 999;
  int maxRow = -999;
  int k = 0;
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      if (this->craftingGrid[k].first->getName() != "-") {
        if (i + 1 < minRow) {
          minRow = i + 1;
        }
        if (i + 1 > maxRow) {
          maxRow = i + 1;
        }
      }
      k++;
    }
  }
  return (maxRow == -999) ? 0 : maxRow - minRow + 1;
}
int Inventory::getCraftingCols() {
  int minCol = 999;
  int maxCol = -999;
  int k = 0;
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      if (this->craftingGrid[k].first->getName() != "-") {
        if (j + 1 < minCol) {
          minCol = j + 1;
        }
        if (j + 1 > maxCol) {
          maxCol = j + 1;
        }
      }
    }
  }
  return (maxCol == -999) ? 0 : maxCol - minCol + 1;
}