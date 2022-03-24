#include "tools.hpp"
#include <iostream>
using namespace std;

int main() {
  Tools defaultTools;
  cout << defaultTools.print() << endl;
  Tools userDefinedNontools(3, "WOODEN_SWORD", 10);
  cout << userDefinedNontools.print() << endl;
  userDefinedNontools.decreaseDurability(5);
  if (userDefinedNontools.isTool()) {
    cout << userDefinedNontools.print() << endl;
  }
}