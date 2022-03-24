#include "item.hpp"
#include <iostream>
using namespace std;

void printItem(Item& i) {
  cout << "=============" << endl;
  cout << i.getId() << endl;
  cout << i.getName() << endl;
  cout << i.getCategory() << endl;
}

int main() {
  Item defaultItem;
  Item userDefinedItem(3, "BIRCH_PLANK", "PLANK");
  printItem(defaultItem);
  printItem(userDefinedItem);
}