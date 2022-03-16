#include "Inventory.hpp"

int main () {
    Inventory *ayam = new Inventory();
    ayam->Add("I0",20);
    ayam->Add("I0",43);
    ayam->Discard("I0",44);
    ayam->Show();
}