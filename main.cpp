#include "lib/Game/game.hpp"

int main()
{
  try {
    string configPath = "./config";
    Game game(configPath);
    game.StartGame();
  } catch (BaseException *e) {
    e->what();
  }
  return 0;
}