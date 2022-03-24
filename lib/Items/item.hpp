#ifndef __ITEM_HPP_
#define __ITEM_HPP_

#include <string>
using namespace std;

class Item
{
protected:
  int id;
  string name;
  string category;

public:
  Item();
  Item(int, string, string);
  Item(int, string);
  int getId() const;
  void setId(int id);
  string getName() const;
  void setName(string name);
  string getCategory() const;
  void setCategory(string category);
  virtual string print() const { return "EMPTY"; }
  virtual int getQuantity() const { return -999; }
  virtual void addQuantity(int) {}
  virtual int getDurability() const { return -999; }
  virtual void decreaseDurability(int) {}
  virtual bool isNontool() { return false; }
  virtual bool isTool() { return false; }
};

#endif