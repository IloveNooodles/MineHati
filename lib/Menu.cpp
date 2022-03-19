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
    cout << "Destroy matrix" << endl;
}
void Menu::MoveToCraft(string src, int n, string* dest) //move dari inventory ke crafting grid
{
    int i = stoi(src.substr(1));
    if (i < 0 || i > 26) {
        throw ("Id tidak ditemukan"); 
    }
    if(this->storage[i].first->getQuantity()==-999 ||(this->storage[i].first->isTool()&&n>1))
    {
        throw("Not available");
    }
    for(int k=0; k<n; k++)
    {
        int j = stoi(dest[k].substr(1));
        if (j < 0 || j > 8) 
        {
            throw ("Id tidak ditemukan"); 
        }   
        Item *s = storage[i].first;
        if(this->craftingGrid[j].first->getName() != "-")
        {
            throw("salah satu petak telah terisi");
        }
        if(storage[i].first->isNontool())
        {
            craftingGrid[j] = make_pair(new Nontools(s->getId(), s->getName(), s->getCategory(), 1),this->craftingGrid[j].second);
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
    int i = stoi(src.substr(1));
    int j = stoi(dest.substr(1));
    Item *s = craftingGrid[i].first;
    Item *d = storage[j].first;
    if (i < 0 || i > 9 || j < 0 || j > 26) {
        throw ("Id tidak ditemukan"); 
    }
    if(s->getName() == "-")
    {
        throw("No item found");
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
void Menu::Export() {}
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
}

void Menu::give(ItemsReader &items, string name, int qty)
{
  if (items.getCtg(name) == "TOOL")
  {
    int i = 0;
    while (i < 27 && qty > 0)
    {
      if (storage[i].first->getName() == "-")
      {
        this->storage[i] = make_pair(new Tools(items.getID(name), name, 10), this->storage[i].second);
        qty--;
      }
      i++;
    }
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
  }
}
pair<Item*,string> Menu::getElement(int i, int j)
{
    return this->craftingGrid[3*i+j];
}