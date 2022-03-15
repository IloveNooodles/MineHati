#include "Slot.hpp"

Slot::Slot() {
    this->id = "";
    this->item = Item();
    this->quantity = 0;
}
Slot::Slot(string id, Item item, int quantity) {
    this->id = id;
    this->item = item;
    this->quantity = quantity;   
}
Item Slot::getItem() {
    return this->item;
}        
int Slot::getQuantity() {
    return this->quantity;
}
string Slot::getId() {
    return this->id;
}
void Slot::setItem(Item item) {
    this->item = item;
}
void Slot::setQuantity(int quantity) {
    if (quantity < 0) {
        throw ("non-positive integer");
    }
    this->quantity = quantity;
}
void Slot::setId(string id) {
    this->id = id;
}