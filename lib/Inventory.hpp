#include "Menu.hpp"
#include "ItemsReader.hpp"
#include "RecipesReader.hpp"
#include <utility>
#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

class Inventory : public Menu
{
public:
  Inventory();
  virtual ~Inventory();
  void Discard(string, int);
  void Use(string);
  void MoveInventory(string src, string dest);
  void Craft(ItemsReader& items, RecipesReader& recipes);
  void EmptyCrafting();
  int getCraftingRows();
  int getCraftingCols();
};
#endif