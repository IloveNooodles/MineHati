#include "Menu.hpp"
#include "ItemsReader.hpp"
#include <utility>
#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

class Inventory : public Menu
{
public:
  virtual ~Inventory();
  void give(ItemsReader& items, string name, int quantity, int dura);
  void give(ItemsReader& items, string name, int quantity);
  void Discard(string, int);
  void Use(string);
  void MoveInventory(string src, string dest);
};
#endif