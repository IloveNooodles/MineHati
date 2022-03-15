#include "Item.hpp"

#ifndef __NONTOOLS_HPP_
#define __NONTOOLS_HPP_

class Nontools : public Item
{
public:
  void init();
  Nontools();
  Nontools(int, string, string);
  Nontools(const Nontools &);
  ~Nontools();
};

#endif