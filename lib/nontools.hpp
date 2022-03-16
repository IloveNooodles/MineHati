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
  Nontools(const Nontools &);
  ~Nontools();
  string print() const;
  int getQuantity() const;
  void setQuantity(int);
  int getDurability() const;
  void setDurability(int);
};

#endif