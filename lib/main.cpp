#include "Inventory.hpp"
#include "Crafting.hpp"

int main () {
    // ItemsReader items;
    // RecipesReader recipes;
    Inventory *ayam = new Inventory();
    ayam->Add("ayam",4);
    ayam->Add("ayam",54);
    ayam->Add("ayam",8);
    // ayam->Use("I0");
    ayam->Show();
    cout<<endl;
    ayam->MoveTumpuk("I1", 1, "I0");
    ayam->Show();
    
    
}