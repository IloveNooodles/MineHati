#ifndef __MENU_HPP__
#define __MENU_HPP__
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Menu {
    protected:
        pair<int,int> *storage[3];
        int size;
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