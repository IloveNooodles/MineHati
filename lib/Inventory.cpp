#include "Inventory.hpp"

Inventory::Inventory() : Menu() {
    this->capacity = 27;
    this->storage = new pair<Item*,string>[27];
    for (int i = 0;i < 27;i++) {
        this->storage[i] = make_pair(new Nontools(),"I" + to_string(i));
    }
}

Inventory::~Inventory() {
    delete[] this->storage;
}

void Inventory::Add(string Name, int b) {
    if (b <= 0) {
        throw ("non-positive integer");
    }
    for(int i = 0; i < 27; i++) {
        Item *el = this->storage[i].first;
        if (el->getisTool() == false && el->getName() == Name && el->getQuantity() + b <= 64) {
            this->storage[i].first->setQuantity(b + el->getQuantity());
            return;
        }
    }
    // tidak ditemukan slot sesuai ketentuan, cari slot kosong
    for(int i = 0; i < 27; i++) {
        Item *el = this->storage[i].first;
        if (el->getName() == "none") {
            this->storage[i] = make_pair(new Tools(1,Name,"wood",b),this->storage[i].second); //TODO masih coba coba
            return;
        }
    }
    throw ("Slot kosong tidak ditemukan");
}

void Inventory::Discard(string Id, int quantity) {
    if (quantity <= 0) {
        throw ("non-positive integer");
    }
    int i = stoi(Id.substr(1));
    if (i < 0 || i > 26) {
        throw ("Id tidak ditemukan"); 
    }
    if (this->storage[i].first->getisTool() == true) {
        if (quantity > 1) {
             throw ("Jumlah yang dibuang melebihi kuantitas");
        }
        this->storage[i] = make_pair(new Nontools(),this->storage[i].second);
    }
    if (quantity > this->storage[i].first->getQuantity()) {
        throw ("Jumlah yang dibuang melebihi kuantitas");
    }
    this->storage[i].first->setQuantity(this->storage[i].first->getQuantity() - quantity);
    if (this->storage[i].first->getQuantity() == 0) {
        this->storage[i] = make_pair(new Nontools(),this->storage[i].second);
    } 
}

void Inventory::Use(string Id) {
    int i = stoi(Id.substr(1));
    if (i < 0 || i > 26) {
        throw ("Id tidak ditemukan"); 
    }
    if (this->storage[i].first->getisTool() == false) {
        throw ("Bukan tools");
    }
    this->storage[i].first->setDurability(this->storage[i].first->getDurability() - 1);
    if (this->storage[i].first->getDurability() == 0) {
        this->storage[i] = make_pair(new Nontools(),this->storage[i].second);
    } 
}