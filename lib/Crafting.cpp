#include "Crafting.hpp"
#include <vector>

Crafting::~Crafting()
{
    delete[] this->craftingGrid;
}