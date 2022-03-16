#ifndef __NONTOOLS_HPP_
#define __NONTOOLS_HPP_
#include "Item.hpp"

class Nontools : public Item
{
private:
  int quantity;
public:
  Nontools();
  Nontools(int, string, string, int);
  Nontools(int, string, int);
  Nontools(const Nontools &);
  string print() const;
  int getQuantity() const;
  void addQuantity(int);
  bool isNontool();
};

#endif