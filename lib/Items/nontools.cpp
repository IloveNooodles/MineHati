#include "nontools.hpp"

Nontools::Nontools() : Item() { this->quantity = 0; }

Nontools::Nontools(int id, string name, string category, int quantity)
    : Item(id, name, category) {
  this->quantity = quantity;
}

Nontools::Nontools(int id, string name, int quantity) : Item(id, name) {
  this->quantity = quantity;
}

string Nontools::print() const {
  return (this->getName() + " " + to_string(this->getQuantity()));
}

int Nontools::getQuantity() const { return this->quantity; }

void Nontools::addQuantity(int quantity) { this->quantity += quantity; }

bool Nontools::isNontool() { return true; }
