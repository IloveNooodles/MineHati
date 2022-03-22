#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <utility>
#include "../Items/item.hpp"
#include "../Items/nontools.hpp"
#include "../Items/tools.hpp"
#include "../IO/ItemsReader.hpp"
#include "../IO/RecipesReader.hpp"
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
  Item* getStorageElmtAtIdx(int);
  string getStorageSlotName(int);
  string getCraftSlotName(int);
  Item* getCraftElmtAtIdx(int);
  int getCraftingRows();
  int getCraftingCols();
  void setCraftingGridAtIdx(int, Item*, string);
  void setStorageAtIdx(int, Item*, string);
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
  void emptyCrafting();
};
#endif