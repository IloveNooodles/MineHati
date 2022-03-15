#include "tools.hpp"

void Tools::init()
{
  this->id = -999;
  this->name = "none";
  this->category = "none";
  this->isTool = true;
}

Tools::Tools()
{
  init();
  this->durability = -999;
}

Tools::Tools(int id, string name, string category, int durability)
{
  this->id = id;
  this->name = name;
  this->category = category;
  this->isTool = true;
  this->durability = -999;
}

Tools::Tools(const Tools &anotherTools)
{
  this->id = anotherTools.id;
  this->name = anotherTools.name;
  this->category = anotherTools.category;
  this->durability = anotherTools.durability;
}

Tools::~Tools()
{
}

int Tools::getDurability() const
{
  return this->durability;
}

void Tools::setDurability(int durability)
{
  this->durability = durability;
}