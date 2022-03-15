#include "Craft.hpp"
#include "Menu.hpp"

Craft::Craft() : Menu() {
    this->capacity = 9;
    for (int i = 0;i < 3;i++) {
        this->storage[i] = new pair<int,int>[3];
        for (int j = 0; j < 3;j++) {
            storage[i][j] = make_pair(i,j);
        }
    }
}

Craft::~Craft() {
    for (int i = 0; i < 3; i++) {
        delete[] this->storage[i];
    }
}