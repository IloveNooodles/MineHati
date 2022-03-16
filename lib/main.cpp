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
    string dest[3] = {"C1", "C2", "C5"};
    ayam->MoveToCraft("I1", 3, dest);
    ayam ->Show();
    cout<<endl;
    
    
}