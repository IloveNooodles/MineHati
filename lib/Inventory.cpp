#include "Inventory.hpp"

Inventory::Inventory() : Menu() {
    this->capacity = 27;
    this->storage = new Slot[27];
    for (int i = 0;i < 27;i++) {
        storage[i] = Slot("I" + to_string(i), Nontools(), 0);
    }
}

Inventory::~Inventory() {
    delete[] this->storage;
}

void Inventory::Add(string Name, int b) {
    Slot el;
    if (b <= 0) {
        throw ("non-positive integer");
    }
    for(int i = 0; i < 27; i++) {
        el = this->storage[i];
        if (el.getItem().getName() == Name && el.getQuantity() + b <= 64) {
            this->storage[i].setQuantity(el.getQuantity() + b);
            return;
        }
    }
    // tidak ditemukan slot sesuai ketentuan, cari slot kosong
    for(int i = 0; i < 27; i++) {
        el = this->storage[i];
        if (el.getItem().getName() == "none") {
            // TODO setItem belum tau gmn
            this->storage[i].setQuantity(b);
            return;
        }
    }
    throw ("Slot kosong tidak ditemukan");
}

void Inventory::Discard(string Id, int quantity) {
    if (quantity <= 0) {
        throw ("non-positive integer");
    }
    for(int i = 0; i < 27; i++) {
        if (this->storage[i].getId() == Id) {
            if (quantity > this->storage[i].getQuantity()) {
                throw ("Jumlah yang dibuang melebihi kuantitas");
            }
            else {
                this->storage[i].setQuantity(this->storage[i].getQuantity() - quantity);
                if (this->storage[i].getQuantity() == 0) {
                    this->storage[i].setItem(Nontools());
                }
            }
            return;
        }
    }
    throw ("Id tidak ditemukan");    
}

void Inventory::Use(string id) {
    for(int i = 0; i < 27; i++) {
        if (this->storage[i].getId() == id) {
            if (this->storage[i].getItem().getisTool() == false) {
                throw ("Item yang dipakai bukan tool");
            }
            else {
                // TODO ubah tools belum tau gmn (gabisa manggil method durability)
            }
            return;
        }
    }    
    throw ("Id tidak ditemukan");   
}