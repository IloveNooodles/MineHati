#ifndef __SLOT_HPP__
#define __SLOT_HPP__
#include <iostream>
#include <string>
#include "Item.hpp"
#include "nontools.hpp"
#include "tools.hpp"
using namespace std;

class Slot {
    private:
        int quantity;
        Item item;
        string id;
    public:
        Slot();
        Slot(string id, Item item, int quantity);
        Item getItem();
        int getQuantity();
        string getId();
        void setItem(Item);
        void setQuantity(int);
        void setId(string);
};
#endif