#include "tools.hpp"

Tools::Tools() : Item() { this->durability = -999; }

Tools::Tools(int id, string name, string category, int durability)
    : Item(id, name, category) {
  this->durability = durability;
}

Tools::Tools(int id, string name, int durability) : Item(id, name) {
  this->durability = durability;
}

string Tools::print() const {
  return (this->getName() + " [" + to_string(this->getDurability()) + "/10]");
}

int Tools::getQuantity() const { return 1; }

int Tools::getDurability() const { return this->durability; }

void Tools::decreaseDurability(int durability) {
  this->durability -= durability;
}
bool Tools::isTool() { return true; }