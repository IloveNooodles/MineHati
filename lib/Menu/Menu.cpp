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
  //remove the current crafting grid first then make new
  delete[] this->storage;
  delete[] this->craftingGrid;
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

//check if the slot is available or not
//TODO: insert exception
int Menu::checkId(string Id, string arrayType) {
  int i = 0;
  i = stoi(Id.substr(1));
  if (arrayType == "INVENTORY" && (i < 0 || i > 26)) {
      throw ("ID not found"); 
  }else if (arrayType == "CRAFT" && (i < 0 || i > 8)) {
      throw ("ID not found"); 
  }
  return i;
}

//getter storage elemt
Item* Menu::getStorageElmtAtIdx(int index) {
  return this->storage[index].first;
}

//getter storage slot name
string Menu::getStorageSlotName(int index) {
  return this->storage[index].second;
}

//getter storage elmt
Item *Menu::getCraftElmtAtIdx(int index) {
  return this->craftingGrid[index].first;
}

//getter craft slot name
string Menu::getCraftSlotName(int index) {
  return this->craftingGrid[index].second;
}

//setter storage elmt
void Menu::setStorageAtIdx(int index, Item* i, string name) {
  this->storage[index] = make_pair(i, name);
}

//setter craft elmt
void Menu::setCraftingGridAtIdx(int index, Item* i, string name){
  this->craftingGrid[index] = make_pair(i, name);
}

//TODO: insert exception
void Menu::MoveToCraft(string src, int qty, string* dest) //move dari inventory ke crafting grid
{
    int i = checkId(src, "INVENTORY");
    Item *s = getStorageElmtAtIdx(i);
    // if element is empty or move tool > 1
    if(s->getName()=="-" ||(s->isTool() && qty > 1))
    {
        throw("Not available");
    }
    //loop the destination slot and check if slot is empty
    for(int k = 0; k < qty; k++)
    {
        int j = checkId(dest[k], "CRAFT");
        Item *crft = getCraftElmtAtIdx(j);
        //if item in s in nontool
        if(s->isNontool())
        {
          //if already exists with the same item
          if(crft->getName() == s->getName())
          {
            //if the slot have over 64 qty else add 1
            if(crft->getQuantity() >= 64)
            {
              throw("Slot is full");
            }
            crft->addQuantity(1);
          }
          //if the same is empty set the slot to current item
          else
          {
            setCraftingGridAtIdx(j, new Nontools(s->getId(), s->getName(), s->getCategory(), 1), getCraftSlotName(j));
          }
          s->addQuantity(-1);
          //if the element we remove only one then set the storage empty
          if(s->getQuantity()==0)
          {
            setStorageAtIdx(i, new Item(), getStorageSlotName(i));
          }
        }
        //the item is tool then we cannot overwrite the item in the craft
        else
        {
            if(getCraftElmtAtIdx(j)->getName() != "-")
            {
                throw("salah satu petak telah terisi");
            }
            //set the craft and reomve from storage
            setCraftingGridAtIdx(j, new Tools(s->getId(), s->getName(), s->getCategory(), s->getDurability()), getCraftSlotName(j));
            setStorageAtIdx(i, new Item(), getStorageSlotName(i));
        }
    }
}

//move from crafting grid ke inventory
void Menu::MoveFromCraft(string src, string dest) 
{
    int i = checkId(src, "CRAFT");
    int j = checkId(dest, "INVENTORY");
    Item *s = getCraftElmtAtIdx(i);
    Item *d = getStorageElmtAtIdx(j);
    
    //move empty item to something
    if(s->getName() == "-")
    {
        throw ("Not available");
    }
    //if the dest is empty
    if(d->getName()=="-")
    {
        //move nontool to dest
        if(s->isNontool())
        {
            setStorageAtIdx(j, new Nontools(s->getId(), s->getName(), s->getCategory(), 1), getStorageSlotName(j));
            s->addQuantity(-1);
            //after remove if the qrt < 0 then remove
            if(s->getQuantity()<=0)
            {
              setCraftingGridAtIdx(i, new Item(), getCraftSlotName(i));
            }
        }
        //source is tools
        else
        {
            setStorageAtIdx(j, new Tools(s->getId(), s->getName(), s->getCategory(), s->getDurability()), getStorageSlotName(j));
            setCraftingGridAtIdx(i, new Tools(), getCraftSlotName(i));
        }
        
    }
    //move the same item nontools
    else if(s->getId() == d->getId() && s->isNontool())
    {
        d->addQuantity(1);
        s->addQuantity(-1);
        //if after remove qty <= 0 remove
        if(s->getQuantity()<=0)
        {
          setCraftingGridAtIdx(i, new Item(), getCraftSlotName(i));
        }
    }
    else
    {
        throw("Failed to move item");
    }
}

//move from inv to inv
void Menu::MoveInventory(string src, string dest)
{
    int i = checkId(src, "INVENTORY");
    int j = checkId(dest, "INVENTORY");
    Item *s = getStorageElmtAtIdx(i);
    Item *d = getStorageElmtAtIdx(j);
    //move tools to tools
    if (!s->isNontool() && !d->isNontool())
    {
        throw("Item yang ditumpuk bukan non-tools");
    }
    // leftover empty slot
    int sisa = 64 - d->getQuantity();
    if (s->getQuantity() <= sisa)
    {
        d->addQuantity(s->getQuantity());
        setStorageAtIdx(i, new Item(), getStorageSlotName(i));
    }
    else
    {
        d->addQuantity(sisa);
        s->addQuantity(-1 * sisa);
    }
}

//add spesific tool to inv
void Menu::give(ItemsReader &items, string name, int qty, int dura)
{
  if (items.getCtg(name) == "TOOL")
  {
    /* Cari slot untuk dimasukkan tool */
    int i = 0;
    //loop through the inv
    while (i < 27 && qty > 0)
    {
      Item *s = getStorageElmtAtIdx(i);
      //if the slot is empty add the item
      if (s->getName() == "-")
      {
        setStorageAtIdx(i, new Tools(items.getID(name), name, dura), getStorageSlotName(i));
        qty--;
      }
      i++;
    }
  }
  else {
    throw ("Bukan tools");
  }
}

//add item to inv
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
      Item *s = getStorageElmtAtIdx(i);
      if (s->getName() == name)
      {
        if (qty + s->getQuantity() <= 64)
        {
          s->addQuantity(qty);
          qty = 0;
        }
        else
        {
          int sisa = 64 - s->getQuantity();
          s->addQuantity(sisa);
          qty -= sisa;
        }
      }
      i++;
    }
    /* Cari slot yang kosong untuk dimasukkan nontool */
    i = 0;
    while (i < 27 && qty > 0)
    {
      Item *s = getStorageElmtAtIdx(i);
      if (s->getName() == "-")
      {
        if (qty <= 64)
        {
          setStorageAtIdx(i, new Nontools(items.getID(name), name, items.getType(name), qty), getStorageSlotName(i));
          qty = 0;
        }
        else
        {
          setStorageAtIdx(i, new Nontools(items.getID(name), name, items.getType(name), 64), getStorageSlotName(i));
          qty -= 64;
        }
      }
      i++;
    }
    if (qty > 0) {
      throw ("Some items cannot added to inventory because inventory is full");
    }
  }
}

//throw away item
void Menu::Discard(string Id, int quantity)
{
  if (quantity <= 0)
  {
    throw("non-positive integer");
  }
  int i = checkId(Id, "INVENTORY");
  Item *s = getStorageElmtAtIdx(i);
  //if the slot item is tool then the qty is only 1
  if (s->isTool())
  {
    if (quantity > 1)
    {
      throw ("the quantitiy is more than the amount");
    }
    setStorageAtIdx(i, new Item(), getStorageSlotName(i));
  }
  //if the quantity is more than amount
  if (quantity > s->getQuantity())
  {
    throw("the quantitiy is more than the amount");
  }
  s->addQuantity((-1) * quantity);
  if (s->getQuantity() == 0)
  {
    setStorageAtIdx(i, new Item(), getStorageSlotName(i));
  }
}

//use tools
void Menu::Use(string Id)
{
  int i = checkId(Id, "INVENTORY");
  Item *s = getStorageElmtAtIdx(i);
  if (!s->isTool())
  {
    throw ("Nontools cannot be use");
  }
  s->decreaseDurability(1);
  if (s->getDurability() <= 0)
  {
    setStorageAtIdx(i, new Item(), getStorageSlotName(i));
  }
}

//show crafting grid and inv
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

//clear the craft
void Menu::emptyCrafting()
{
  for(int i = 0; i<craftingCapacity; i++)
  {
    setCraftingGridAtIdx(i, new Item(), getCraftSlotName(i));
  }
}