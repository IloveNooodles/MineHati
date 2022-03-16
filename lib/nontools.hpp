#include "Item.hpp"

#ifndef __NONTOOLS_HPP_
#define __NONTOOLS_HPP_

class Nontools : public Item
{
private:
  int quantity;
public:
  Nontools();
  Nontools(int, string, string, int);
  Nontools(const Nontools &);
  ~Nontools();
  int getQuantity() const;
  void setQuantity(int);
  int getDurability() const;
  void setDurability(int);
};

#endif