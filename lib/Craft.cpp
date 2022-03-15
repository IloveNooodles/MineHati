#include "Craft.hpp"
#include "Menu.hpp"

Craft::Craft() : Menu() {
    this->capacity = 9;
    this->storage = new Slot[9];
    for (int i = 0;i < 9;i++) {
        storage[i] = Slot("I" + to_string(i), Item(), 0);
    }
}

Craft::~Craft() {
    delete[] this->storage;
}