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
  Tools(int, string, int);
  Tools(const Tools &);
  string print() const;
  int getQuantity() const;
  int getDurability() const;
  void decreaseDurability(int);
  bool isTool();
};

#endif