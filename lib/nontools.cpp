#include "Nontools.hpp"

Nontools::Nontools()
{
  this->id = -999;
  this->name = "none";
  this->category = "none";
  this->isTool = false;
  this->quantity = 0;
}

Nontools::Nontools(int id, string name, string category, int quantity)
{
  this->id = id;
  this->name = name;
  this->category = category;
  this->isTool = false;
  this->quantity = quantity;
}

Nontools::~Nontools() {}

Nontools::Nontools(const Nontools &anotherTools)
{
  this->id = anotherTools.id;
  this->name = anotherTools.name;
  this->category = anotherTools.category;
  this->quantity = anotherTools.quantity;
}

int Nontools::getQuantity() const
{
  return this->quantity;
}

void Nontools::setQuantity(int quantity)
{
  this->quantity = quantity;
}

int Nontools::getDurability() const
{
  throw ("Bukan tools");
}

void Nontools::setDurability(int durability)
{
  throw ("Bukan tools");
}
