#include "Inventory.hpp"
#include "Crafting.hpp"

int main () {
    // ItemsReader items;
    // RecipesReader recipes;
    Inventory *ayam = new Inventory();
    ItemsReader items;
    ayam->give(items,"OAK_LOG",41);
    ayam->give(items,"DIAMOND",8);
    ayam->give(items,"OAK_LOG",25);
    ayam->give(items,"DIAMOND_AXE",11,7);
    ayam->Show();
    cout<<endl;
    
    
}