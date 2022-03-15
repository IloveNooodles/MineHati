#include "item.hpp"

void Item::init()
{
  this->id = -999;
  this->name = "none";
  this->category = "none";
  this->isTool = false;
}

int Item::getId() const
{
  return this->id;
}
void Item::setId(int id)
{
  this->id = id;
}
string Item::getName() const
{
  return this->name;
}
void Item::setName(string name)
{
  this->name = name;
}
string Item::getCategory() const
{
  return this->category;
}
void Item::setCategory(string category)
{
  this->category = category;
}
bool Item::getisTool() const
{
  return this->isTool;
}
void Item::setisTool(bool isTool)
{
  this->isTool = isTool;
}