#ifndef __TOOLS_HPP_
#define __TOOLS_HPP_
#include "Item.hpp"

// durability 0;

class Tools : public Item
{
private:
  int durability;

public:
  Tools();
  Tools(int, string, string, int);
  Tools(const Tools &);
  ~Tools();
  string print() const;
  int getQuantity() const;
  void setQuantity(int);
  int getDurability() const;
  void setDurability(int);
};

#endif