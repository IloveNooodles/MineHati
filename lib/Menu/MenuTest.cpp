#include "Menu.hpp"

int main() {
  Menu menu;
  ItemsReader items = ItemsReader("../../config/item.txt");
  RecipesReader recipes = RecipesReader("../../config/recipe");
  menu.Show();
  menu.give(items, "OAK_PLANK", 1);
  menu.give(items, "BIRCH_PLANK", 2);
  menu.give(items, "STICK", 1);
  menu.MoveToCraft("I0", 1, {"C0"});
  menu.MoveToCraft("I1", 1, {"C3"});
  menu.Craft(items, recipes);
  menu.Discard("I2", 2);
  menu.Show();
  menu.give(items, "WOODEN_SWORD", 1);
  menu.Use("I0");
  menu.Show();
  menu.exportInventory(items, "./menuTest.out");
}