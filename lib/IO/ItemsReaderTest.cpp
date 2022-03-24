#include "ItemsReader.hpp"

int main() {
  ItemsReader items("../../config/item.txt");
  cout << items.getID("OAK_PLANK") << endl;
  cout << items.getCtg("OAK_PLANK") << endl;
  cout << items.getType("OAK_PLANK") << endl;
}