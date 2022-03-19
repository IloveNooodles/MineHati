#include "Menu.hpp"

int main()
{
  Menu *ayam = new Menu();
  ItemsReader items;
  RecipesReader recipes;
  ayam->give(items, "OAK_LOG", 41);
  ayam->give(items, "DIAMOND", 8);
  ayam->give(items, "OAK_LOG", 25);
  ayam->give(items, "DIAMOND_AXE", 11, 7);
  ayam->Show();
  cout<<endl;
  string dest[3] = {"C0", "C1", "C3"};
  string dest2[2] = {"C4", "C7"};
  ayam->MoveToCraft("I1", 3, dest);
  ayam->MoveToCraft("I4", 1, dest2);
  ayam->Show();
  cout<<endl;
  ayam->MoveFromCraft("C0", "I1");
  ayam->MoveFromCraft("C1", "I20");
  ayam->MoveFromCraft("C4", "I26");
  ayam->Show();
  cout<<endl;
  ayam->MoveInventory("I0","I2");
  ayam->Discard("I2",12);
  ayam->Use("I3");
  ayam->MoveFromCraft("C3", "I1");
  ayam->Show();
  cout<<endl;
  ayam->MoveToCraft("I3", 1, dest);
  ayam->MoveToCraft("I5", 1, dest2);
  ayam->Show();
  cout<<endl;
  ayam->Craft(items, recipes);
  ayam->give(items, "STICK", 11);
  ayam->Show();
  cout<<endl;
  ayam->MoveToCraft("I4", 2, dest2);
  ayam->MoveToCraft("I1", 3, dest);
  ayam->Show();
  cout<<endl;
  ayam->Craft(items, recipes);
  ayam->Show();
  cout<<endl;
}