#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <utility>
#include "item.hpp"
#include "nontools.hpp"
#include "tools.hpp"
#include "ItemsReader.hpp"
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
  int checkId(string Id);
  void MoveToCraft(string src, int n, string* dest);
  void MoveFromCraft(string src, string dest);
  void MoveInventory(string src, string dest);
  void give(ItemsReader& items, string name, int quantity, int dura);
  void give(ItemsReader& items, string name, int quantity);
  void Discard(string, int);
  void Use(string);
  void Show();
  void exportInventory(ItemsReader& items, string loc);
};
#endif