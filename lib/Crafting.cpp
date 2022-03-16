#include "Crafting.hpp"
#include <vector>

Crafting::Crafting() : Menu()
{
    this->craftingCapacity = 9;
    this->craftingGrid = new pair<Item*,string>[9];
    for (int i = 0;i < 9;i++) {
        this->craftingGrid[i] = make_pair(new Nontools(),"C" + to_string(i));
    }
}
Crafting::~Crafting()
{
    delete[] this->craftingGrid;
}