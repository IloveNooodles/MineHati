#include "Nontools.hpp"

void Nontools::init()
{
  this->id = -999;
  this->name = "none";
  this->category = "none";
  this->isTool = false;
}

Nontools::Nontools()
{
  init();
}

Nontools::Nontools(int id, string name, string category)
{
  this->id = id;
  this->name = name;
  this->category = category;
  this->isTool = false;
}

Nontools::Nontools(const Nontools &newNontools)
{
  this->id = newNontools.id;
  this->name = newNontools.name;
  this->category = newNontools.category;
}

Nontools::~Nontools()
{
}
