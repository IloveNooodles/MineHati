#include "Menu.hpp"
#include <typeinfo>

Menu::Menu() {
    this->craftingCapacity = 9; //init craftingGrid
    this->craftingGrid = new pair<Item*,string>[9];
    for (int i = 0;i < 9;i++) {
        this->craftingGrid[i] = make_pair(new Item(),"C" + to_string(i));
    }

    this->capacity = 27; //init storage
    this->storage = new pair<Item*,string>[27];
    for (int i = 0;i < 27;i++) {
        this->storage[i] = make_pair(new Item(),"I" + to_string(i));
    }
}

Menu::~Menu() {
    delete[] this->storage;
    delete[] this->craftingGrid;
}

Menu& Menu::operator=(const Menu& menu) {
  this->craftingCapacity = menu.craftingCapacity;
  this->capacity = menu.capacity;
  this->storage = new pair<Item*,string>[menu.capacity];
  for (int i = 0;i < menu.capacity;i++) {
    this->storage[i] = menu.storage[i];
  }
  this->craftingGrid = new pair<Item*,string>[menu.craftingCapacity];
  for (int i = 0;i < menu.craftingCapacity;i++) {
    this->craftingGrid[i] = menu.craftingGrid[i];
  }
  return *this;  
}

int Menu::checkId(string Id, string array) {
  int i = 0;
  if (array == "INVENTORY") {
    i = stoi(Id.substr(1));
    if (i < 0 || i > 26) {
      throw ("ID not found"); 
    }
  }
  else if (array == "CRAFT") {
    i = stoi(Id.substr(1));
    if (i < 0 || i > 8) {
      throw ("ID not found"); 
    }
  }
  return i;
}

void Menu::MoveToCraft(string src, int n, string* dest) //move dari inventory ke crafting grid
{
    int i = checkId(src, "INVENTORY");
    Item *s = storage[i].first;
    if(this->storage[i].first->getName()=="-" ||(this->storage[i].first->isTool()&&n>1) || this->storage[i].first->getName() != s->getName())
    {
        throw("Not available");
    }
    for(int k=0; k<n; k++)
    {
        int j = checkId(dest[k], "CRAFT");
        if(s->isNontool())
        {
          if(craftingGrid[j].first->getName() == s->getName())
          {
            if(craftingGrid[j].first->getQuantity()>=64)
            {
              throw("Slot is full");
            }
            craftingGrid[j].first->addQuantity(1);
          }
          else
          {
            craftingGrid[j] = make_pair(new Nontools(s->getId(), s->getName(), s->getCategory(), 1),this->craftingGrid[j].second);
          }
          s->addQuantity(-1);
          if(s->getQuantity()==0)
          {
              this->storage[i] = make_pair(new Item(),this->storage[i].second);
          }
        }
        else
        {
            craftingGrid[j] = make_pair(new Tools(s->getId(), s->getName(), s->getCategory(), s->getDurability()),this->craftingGrid[j].second);
            this->storage[i] = make_pair(new Item(),this->storage[i].second);
        }
    }
}
void Menu::MoveFromCraft(string src, string dest) //move dari crafting grid ke inventory
{
    int i = checkId(src, "CRAFT");
    int j = checkId(dest, "INVENTORY");
    Item *s = craftingGrid[i].first;
    Item *d = storage[j].first;
    if(s->getName() == "-")
    {
        throw("Not available");
    }
    if(d->getName()=="-")
    {
        if(s->isNontool())
        {
            storage[j] = make_pair(new Nontools(s->getId(), s->getName(), s->getCategory(), 1),this->storage[j].second);
        }
        else //tools
        {
            storage[j] = make_pair(new Tools(s->getId(), s->getName(), s->getCategory(), s->getDurability()),this->storage[j].second);
        }
        this->craftingGrid[i] = make_pair(new Item(),this->craftingGrid[i].second);
    }
    else if(s->getId() == d->getId() && s->isNontool())
    {
        d->addQuantity(1);
        this->craftingGrid[i] = make_pair(new Item(),this->craftingGrid[i].second);
    }
    else
    {
        throw("Failed to move item");
    }
}
void Menu::MoveInventory(string src, string dest)
{
    int i = checkId(src, "INVENTORY");
    int j = checkId(dest, "INVENTORY");
    if (!this->storage[i].first->isNontool() && !this->storage[j].first->isNontool())
    {
        throw("Item yang ditumpuk bukan non-tools");
    }
    int sisa = 64 - this->storage[j].first->getQuantity();
    if (this->storage[i].first->getQuantity() <= sisa)
    {
        this->storage[j].first->addQuantity(this->storage[i].first->getQuantity());
        this->storage[i] = make_pair(new Item(), this->storage[i].second);
    }
    else
    {
        this->storage[j].first->addQuantity(sisa);
        this->storage[i].first->addQuantity(-1 * sisa);
    }
}
void Menu::give(ItemsReader &items, string name, int qty, int dura)
{
  if (items.getCtg(name) == "TOOL")
  {
    /* Cari slot untuk dimasukkan tool */
    int i = 0;
    while (i < 27 && qty > 0)
    {
      if (storage[i].first->getName() == "-")
      {
        this->storage[i] = make_pair(new Tools(items.getID(name), name, dura), this->storage[i].second);
        qty--;
      }
      i++;
    }
  }
  else {
    throw ("Bukan tools");
  }
}

void Menu::give(ItemsReader &items, string name, int qty)
{
  if (items.getCtg(name) == "TOOL")
  {
    give(items, name, qty, 10);
  }
  else if (items.getCtg(name) == "NONTOOL")
  {
    int i = 0;
    while (i < 27 && qty > 0)
    {
      if (storage[i].first->getName() == name)
      {
        if (qty + storage[i].first->getQuantity() <= 64)
        {
          storage[i].first->addQuantity(qty);
          qty = 0;
        }
        else
        {
          int sisa = 64 - storage[i].first->getQuantity();
          storage[i].first->addQuantity(sisa);
          qty -= sisa;
        }
      }
      i++;
    }
    /* Cari slot yang kosong untuk dimasukkan nontool */
    i = 0;
    while (i < 27 && qty > 0)
    {
      if (storage[i].first->getName() == "-")
      {
        if (qty <= 64)
        {
          storage[i] = make_pair(new Nontools(items.getID(name), name, items.getType(name), qty), this->storage[i].second);
          qty = 0;
        }
        else
        {
          storage[i] = make_pair(new Nontools(items.getID(name), name, items.getType(name), 64), this->storage[i].second);
          qty -= 64;
        }
      }
      i++;
    }
    if (qty > 0) {
      throw ("Beberapa item tidak dapat dimasukkan karena sudah penuh");
    }
  }
}
void Menu::Discard(string Id, int quantity)
{
  if (quantity <= 0)
  {
    throw("non-positive integer");
  }
  int i = checkId(Id, "INVENTORY");
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

void Menu::Use(string Id)
{
  int i = checkId(Id, "INVENTORY");
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
void Menu::Show() {
    for (int i = 0;i < 3;i++) { //craftingGrid
        for (int j = 0; j < this->craftingCapacity/3;j++) {
            cout << "[" << this->craftingGrid[i*this->craftingCapacity/3 + j].second << " " << this->craftingGrid[i*this->craftingCapacity/3 + j].first->print() << "] ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0;i < 3;i++) { //storage
        for (int j = 0; j < this->capacity/3;j++) {
            cout << "[" << this->storage[i*this->capacity/3 + j].second << " " << this->storage[i*this->capacity/3 + j].first->print() << "] ";
        }
        cout << endl;
    }
    cout << endl;
}
void Menu::exportInventory(ItemsReader& items, string loc) {
  ofstream file;
  file.open(loc);
  for (int i = 0; i < 27; i ++) {
    string name = this->storage[i].first->getName();
    if (name == "-") {
      file << "0:0\n";
    } 
    else {
      if (items.getCtg(name) == "TOOL") {
        file << items.getID(name) << ":" << this->storage[i].first->getDurability() << endl;
      } 
      else {
        file << items.getID(name) << ":" << this->storage[i].first->getQuantity() << endl;
      }
    }
  }
  file.close();
}

pair<Item*,string> Menu::getElement(int i, int j)
{
  return this->craftingGrid[3*i+j];
}

void Menu::Craft(ItemsReader& items, RecipesReader& recipes)
{
  vector<Recipe> r = recipes.getRecipes();
  bool recipeFound = false;
  /* Cek apakah tipe yang harus membenarkan atau tidak */
  bool fixedItem = false;
  int itemCount = 0; /* Banyak tool */
  int itemDura[] = {-1, -1};
  string itemName[] = {"-", "-"};
  for (int i = 0; i < 3 && itemCount < 2; i ++) {
    for (int j = 0; j < 3 && itemCount < 2; j ++) {
      string name = this->getElement(i, j).first->getName();
      if (name != "-") {
        if (items.getCtg(name) == "TOOL") {
          itemDura[itemCount] = this->getElement(i, j).first->getDurability();
          itemName[itemCount] = this->getElement(i, j).first->getName();
          itemCount ++;
        } else {
          itemCount += 999; /* Agar keluar dari loop */
        }
      }
    }
  }
  if (itemCount == 2) {
    if (itemName[0] == itemName[1]) {
      /* Boleh melakukan fix */
      fixedItem = true;
    }
  }
  if (fixedItem) {
    /* Yang dilakukan adalah memperbaiki item */
    int dura = (itemDura[0] + itemDura[1] > 10 ? 10 : itemDura[0] + itemDura[1]);
    give(items, itemName[0], 1, dura);
    this->emptyCrafting();
  } else {
    /* Cek setiap resep yang ada di recipe */
    for (int x = 0; x < r.size(); x ++) {
      vector<vector<string>> recipe = r[x].getRecipe();
      int rows = r[x].getRows();
      int cols = r[x].getCols();
      if (rows != this->getCraftingRows() || cols != this->getCraftingCols()) {
        continue;
      }
      /* Looping pada matrix c */
      bool foundDifferent = false;
      for (int i = 0; i < 3 - rows + 1 && !recipeFound; i ++) {
        for (int j = 0; j < 3 - cols + 1 && !recipeFound; j ++) {
          foundDifferent = false;
          for (int k = 0; k < rows && !foundDifferent; k ++) {
            for (int l = 0; l < cols && !foundDifferent; l ++) {
              if (this->getElement(i + k, j + l).first->getName() != "-") {
                string type = items.getType(this->getElement(i + k, j + l).first->getName());
                if (type != "-") {
                  /* Ada tipenya */
                  foundDifferent = type != recipe[k][l];
                } else {
                  /* Tidak ada tipenya */
                  foundDifferent = this->getElement(i + k, j + l).first->getName() != recipe[k][l];
                }
              } else {
                foundDifferent = this->getElement(i + k, j + l).first->getName() != recipe[k][l];
              }
            }
          }
          /* k dan l out of range atau foundDifferent = true */
          if (!foundDifferent) {
            recipeFound = true; 
          }
        }
      }

      if (recipeFound) {
        this->emptyCrafting();
        give(items, r[x].getName(), r[x].getAmount());
      }
    }
  }
  if (!recipeFound && !fixedItem) {
    CraftMirror(items,recipes);
  }
}

void Menu::CraftMirror(ItemsReader& items, RecipesReader& recipes)
{
  vector<Recipe> r = recipes.getRecipes();
  bool recipeFound = false;
  /* Cek setiap resep yang ada di recipe */
  for (int x = 0; x < r.size(); x ++) {
    vector<vector<string>> recipe = r[x].getRecipe();
    int rows = r[x].getRows();
    int cols = r[x].getCols();
    if (rows != this->getCraftingRows() || cols != this->getCraftingCols()) {
      continue;
    }
    /* Looping pada matrix c */
    bool foundDifferent = false;
    for (int i = 0; i < 3 - rows + 1 && !recipeFound; i ++) {
      for (int j = 0; j < 3 - cols + 1 && !recipeFound; j ++) {
        foundDifferent = false;
        for (int k = 0; k < rows && !foundDifferent; k ++) {
          for (int l = 0; l < cols && !foundDifferent; l ++) {
            if (this->getElement(i + k, j + 2 - l).first->getName() != "-") {
              string type = items.getType(this->getElement(i + k, j + 2 - l).first->getName());
              if (type != "-") {
                /* Ada tipenya */
                foundDifferent = type != recipe[k][l];
              } else {
                /* Tidak ada tipenya */
                foundDifferent = this->getElement(i + k, j + 2 - l).first->getName() != recipe[k][l];
              }
            } else {
              foundDifferent = this->getElement(i + k, j + 2 - l).first->getName() != recipe[k][l];
            }
          }
        }
        /* k dan l out of range atau foundDifferent = true */
        if (!foundDifferent) {
          recipeFound = true; 
        }
      }
    }
    if (recipeFound) {
      this->emptyCrafting();
      give(items, r[x].getName(), r[x].getAmount());
    }
  }
  if (!recipeFound) {
    throw ("Gagal melakukan crafting");
  }
}

int Menu::getCraftingRows() {
  int minRow = 999;
  int maxRow = -999;
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      if (this->getElement(i, j).first->getName() != "-") {
        if (i + 1 < minRow) {
          minRow = i + 1;
        }
        if (i + 1 > maxRow) {
          maxRow = i + 1;
        }
      }
    }
  }
  return (maxRow == -999) ? 0 : maxRow - minRow + 1;
}

int Menu::getCraftingCols() {
  int minCol = 999;
  int maxCol = -999;
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j ++) {
      if (this->getElement(i, j).first->getName() != "-") {
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

void Menu::emptyCrafting()
{
  for(int i = 0; i<craftingCapacity; i++)
  {
    this->craftingGrid[i] = make_pair(new Item(), this->craftingGrid[i].second);
  }
}