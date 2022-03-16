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

void Inventory::give(ItemsReader &items, string name, int qty, int dura)
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

void Inventory::give(ItemsReader &items, string name, int qty)
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