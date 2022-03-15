#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include "Slot.hpp"
using namespace std;

class Menu {
    protected:
        Slot *storage;
        int capacity;
    public:
        Menu();
        int getCapacity();
        void setCapacity();
        virtual ~Menu();
        void Export();
        void Move();
        void Show();
};
#endif