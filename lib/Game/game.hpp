#ifndef __GAME_HPP_
#define __GAME_HPP_
#include "../Menu/Menu.hpp"
using namespace std;

class Game {
    private:
        Menu* menu;
        ItemsReader* items;
        RecipesReader* recipe;
        bool gameEnd;
    public:
        Game();
        Game(string filePath);
        void StartGame();
        string askCommand();
        void process(string);
};

#endif