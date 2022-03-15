#include "Menu.hpp"

Menu::Menu() {}
Menu::~Menu() {
    cout << "Destroy matrix" << endl;
}
void Menu::Export() {}
void Menu::Move() {}
void Menu::Show() {
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < this->capacity/3;j++) {
            cout << "[" << this->storage[i*this->capacity/3 + j].getItem().getName() << " " << this->storage[i*this->capacity/3 + j].getQuantity() << "] ";
        }
        cout << endl;
    }
}