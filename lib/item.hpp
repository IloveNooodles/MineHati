#include <string>
using namespace std;

#ifndef __ITEM_HPP_
#define __ITEM_HPP_

/*
TYPE
LOG
PLANK
-
STONE
*/

/*
DEFAULT VALUE
id: -999
name: "none"
category: "none"
*/

static const string enum_category[] = {
    "LOG", "PLANK", "STONE", "-"};

class Item
{
protected:
  int id;
  string name;
  string category;
  bool isTool;

public:
  Item();
  virtual ~Item();
  int getId() const;
  void setId(int id);
  string getName() const;
  void setName(string name);
  string getCategory() const;
  void setCategory(string category);
  bool getisTool() const;
  void setisTool(bool isTool);
  virtual string print() const = 0;
  virtual int getQuantity() const = 0;
  virtual void setQuantity(int) = 0;
  virtual int getDurability() const = 0;
  virtual void setDurability(int) = 0;
};

#endif