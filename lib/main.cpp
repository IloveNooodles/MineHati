#include "Inventory.hpp"

int main () {
    Inventory *ayam = new Inventory();
    ayam->Add("ayam",4);
    ayam->Add("ayam",8);
    ayam->Add("ayam",1);
    ayam->Use("I0");
    ayam->Show();
}