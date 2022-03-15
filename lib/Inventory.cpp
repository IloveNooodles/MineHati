#include "Inventory.hpp"

Inventory::Inventory() : Menu() {
    this->capacity = 27;
    for (int i = 0;i < 3;i++) {
        this->storage[i] = new pair<int,int>[9];
        for (int j = 0; j < 9;j++) {
            storage[i][j] = make_pair(i,j);
        }
    }
}

Inventory::~Inventory() {
    for (int i = 0; i < 3; i++) {
        delete[] this->storage[i];
    }
}