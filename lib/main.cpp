#include "Menu.hpp"

int main()
{
  // ItemsReader items;
  // RecipesReader recipes;
  Menu *ayam = new Menu();
  ItemsReader items;
  ayam->give(items, "OAK_LOG", 41);
  ayam->give(items, "DIAMOND", 8);
  ayam->give(items, "OAK_LOG", 25);
  ayam->give(items, "DIAMOND_AXE", 11, 7);
  string dest[3] = {"C1", "C2", "C7"};
  string dest2[2] = {"C3", "C4"};
  ayam->MoveToCraft("I1", 3, dest);
  ayam->MoveToCraft("I4", 1, dest2);
  ayam->MoveFromCraft("C1", "I1");
  ayam->MoveFromCraft("C2", "I20");
  ayam->MoveFromCraft("C3", "I26");
  ayam->MoveInventory("I0","I2");
  ayam->Discard("I2",12);
  ayam->Use("I3");
  ayam->Show();
}