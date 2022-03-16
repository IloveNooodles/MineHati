#include "Inventory.hpp"
#include "Crafting.hpp"

int main () {
    // ItemsReader items;
    // RecipesReader recipes;
    Crafting *c = new Crafting();
    Inventory *ayam = new Inventory();
    ayam->Add("ayam",4);
    ayam->Add("ayam",8);
    ayam->Add("ayam",1);
    ayam->Use("I0");
    ayam->Show();
}