#include "Item.hpp"

#ifndef __TOOLS_HPP_
#define __TOOLS_HPP_

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
  int getQuantity() const;
  void setQuantity(int);
  int getDurability() const;
  void setDurability(int);
};

#endif