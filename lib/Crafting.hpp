#include "Menu.hpp"
#include "Reader.hpp"
#include <utility>
#ifndef __CRAFTING_HPP__
#define __CRAFTING_HPP__

class Crafting : public Menu
{
public:
  Crafting();
  virtual ~Crafting();
  void Craft();
};
#endif