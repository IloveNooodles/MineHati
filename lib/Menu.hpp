#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <utility>
#include "item.hpp"
#include "nontools.hpp"
#include "tools.hpp"
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
  int getCapacity();
  void setCapacity();
  virtual ~Menu();
  void Export();
  void Show();
};
#endif