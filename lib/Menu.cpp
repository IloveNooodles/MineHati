#include "Menu.hpp"
#include <typeinfo>

Menu::Menu() {
    this->craftingCapacity = 9; //init craftingGrid
    this->craftingGrid = new pair<Item*,string>[9];
    for (int i = 0;i < 9;i++) {
        this->craftingGrid[i] = make_pair(new Nontools(),"C" + to_string(i));
    }

    this->capacity = 27; //init storage
    this->storage = new pair<Item*,string>[27];
    for (int i = 0;i < 27;i++) {
        this->storage[i] = make_pair(new Nontools(),"I" + to_string(i));
    }

}
Menu::~Menu() {
    cout << "Destroy matrix" << endl;
}
void Menu::Export() {}
void Menu::MoveTumpuk(string src, int n, string dest) {
    int isrc = stoi(src.substr(1));
    int idest = stoi(dest.substr(1));
    if (isrc < 0 || isrc > 26)  
    {
        throw ("Id tidak ditemukan");
    }
    if (idest < 0 || idest > 26)  
    {
        throw ("Id tidak ditemukan");
    }
    Item *s = this->storage[isrc].first;
    Item *d = this->storage[idest].first;
    if(d->getId() != s->getId() || s->getisTool())
    {
        throw ("Tidak bisa menumpuk kedua barang ini");
    }
    if(d->getQuantity()+s->getQuantity() <= 64)
    {
        d->setQuantity(s->getQuantity() + d->getQuantity());
        s->setQuantity(0);
    }
    else
    {
        s->setQuantity(d->getQuantity()+s->getQuantity()-64);
        d->setQuantity(64);
    }
    if(s->getQuantity() <= 0)
    {
        this->storage[isrc] = make_pair(new Nontools(),this->storage[isrc].second);
    }
}
void Menu::Show() {
    for (int i = 0;i < 3;i++) { //craftingGrid
        for (int j = 0; j < this->craftingCapacity/3;j++) {
            cout << "[" << this->craftingGrid[i*this->craftingCapacity/3 + j].second << " " << this->craftingGrid[i*this->craftingCapacity/3 + j].first->print() << "] ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0;i < 3;i++) { //storage
        for (int j = 0; j < this->capacity/3;j++) {
            cout << "[" << this->storage[i*this->capacity/3 + j].second << " " << this->storage[i*this->capacity/3 + j].first->print() << "] ";
        }
        cout << endl;
    }
}