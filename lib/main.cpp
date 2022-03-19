#include "Inventory.hpp"
#include "RecipesReader.hpp"

int main()
{
  Inventory *ayam = new Inventory();
  RecipesReader recipes;
  ItemsReader items;
  ayam->give(items, "OAK_LOG", 41);
  ayam->give(items, "DIAMOND", 8);
  ayam->give(items, "OAK_LOG", 25);
  ayam->give(items, "DIAMOND_AXE", 11, 7);
  ayam->Show();
  cout << endl;
  string dest[3] = {"C1", "C0", "C3"};
  string dest2[2] = {"C4", "C7"};
  ayam->MoveToCraft("I1", 3, dest);
  ayam->MoveToCraft("I4", 1, dest2);
  ayam->Show();
  cout << endl;
  ayam->MoveFromCraft("C1", "I1");
  ayam->MoveFromCraft("C0", "I20");
  ayam->MoveFromCraft("C3", "I21");
  ayam->MoveFromCraft("C4", "I26");
  ayam->Show();
  cout << endl;
  ayam->MoveToCraft("I3", 1, dest);
  ayam->MoveToCraft("I5", 1, dest2);
  ayam->Show();
  ayam->Craft(items, recipes);
  ayam->give(items, "STICK", 11);
  ayam->Show();
  ayam->MoveToCraft("I1", 3, dest);
  ayam->MoveToCraft("I4", 2, dest2);
  ayam->Show();
  //ayam->Craft(items, recipes);

}