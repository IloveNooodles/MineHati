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
  virtual void init() = 0;
  int getId() const
  {
    return this->id;
  }
  void setId(int id)
  {
    this->id = id;
  }
  string getName() const
  {
    return this->name;
  }
  void setName(string name)
  {
    this->name = name;
  }
  string getCategory() const
  {
    return this->category;
  }
  void setCategory(string category)
  {
    this->category = category;
  }
  bool getisTool() const
  {
    return this->isTool;
  }
  void setisTool(bool isTool)
  {
    this->isTool = isTool;
  }
};

#endif