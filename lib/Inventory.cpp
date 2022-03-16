#include "Inventory.hpp"

Inventory::Inventory() : Menu() {
    this->capacity = 27;
    this->storage = new Item*[27];
    for (int i = 0;i < 27;i++) {
        this->storage[i] = new Nontools();
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
        Item *el = this->storage[i];
        if (el->getisTool() == false && el->getName() == Name && el->getQuantity() + b <= 64) {
            this->storage[i]->setQuantity(b + el->getQuantity());
            return;
        }
    }
    // tidak ditemukan slot sesuai ketentuan, cari slot kosong
    for(int i = 0; i < 27; i++) {
        Item *el = this->storage[i];
        if (el->getName() == "none") {
            this->storage[i] = new Tools(1,Name,"wood",b); //TODO masih coba coba
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
    if (this->storage[i]->getisTool() == true) {
        if (quantity > 1) {
             throw ("Jumlah yang dibuang melebihi kuantitas");
        }
        this->storage[i] = new Nontools();
    }
    if (quantity > this->storage[i]->getQuantity()) {
        throw ("Jumlah yang dibuang melebihi kuantitas");
    }
    this->storage[i]->setQuantity(this->storage[i]->getQuantity() - quantity);
    if (this->storage[i]->getQuantity() == 0) {
        this->storage[i] = new Nontools();
    } 
}

void Inventory::Use(string Id) {
    int i = stoi(Id.substr(1));
    if (i < 0 || i > 26) {
        throw ("Id tidak ditemukan"); 
    }
    if (this->storage[i]->getisTool() == false) {
        throw ("Bukan tools");
    }
    this->storage[i]->setDurability(this->storage[i]->getDurability() - 1);
    if (this->storage[i]->getDurability() == 0) {
        this->storage[i] = new Nontools();
    } 
}