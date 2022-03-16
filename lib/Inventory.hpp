#include "Menu.hpp"
#include <utility>
#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

class Inventory : public Menu
{
public:
  Inventory();
  virtual ~Inventory();
  void Add(string, int);
  void Discard(string, int);
  void Use(string);
};
#endif