#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <utility>
#include "item.hpp"
#include "nontools.hpp"
#include "tools.hpp"
#include "ItemsReader.hpp"
#include "RecipesReader.hpp"
using namespace std;

class Menu
{
protected:
  pair<Item*,string> *storage;
  pair<Item*,string> *craftingGrid;
  int capacity;
  int craftingCapacity;

public:
  Menu();
  ~Menu();
  Menu& operator=(const Menu& menu);
  int checkId(string Id, string array);
  void MoveToCraft(string src, int n, string* dest);
  void MoveFromCraft(string src, string dest);
  void MoveInventory(string src, string dest);
  void give(ItemsReader& items, string name, int quantity, int dura);
  void give(ItemsReader& items, string name, int quantity);
  void Discard(string, int);
  void Use(string);
  void Show();
  void exportInventory(ItemsReader& items, string loc);
  pair<Item*,string> getElement(int i, int j);
  void CraftMirror(ItemsReader& items, RecipesReader& recipes);
  void Craft(ItemsReader& items, RecipesReader& recipes);
  int getCraftingRows();
  int getCraftingCols();
  void emptyCrafting();
};
#endif