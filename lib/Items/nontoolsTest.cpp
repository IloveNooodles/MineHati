#include "nontools.hpp"
#include <iostream>
using namespace std;

int main() {
  Nontools defaultNontools;
  cout << defaultNontools.print() << endl;
  Nontools userDefinedNontools(3, "BIRCH_PLANK", 3);
  cout << userDefinedNontools.print() << endl;
  userDefinedNontools.addQuantity(20);
  if (userDefinedNontools.isNontool()) {
    cout << userDefinedNontools.print() << endl;
  }
}