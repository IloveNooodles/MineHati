#include "../game.hpp"
using namespace std;

int main(){
  cout << "1. Filepath is wrong\n";
  //
  try {
    Game game;
  } catch (BaseException *e) {
    e->what();
  }
  cout << "2. Filepath is correct\n";
  string dir = "../../../config";
  Game game(dir);

  cout << "3. Command is wrong\n";
  try {
    game.process("AFQWF");
  } catch (BaseException *e){
    e->what();
  }

  cout << "4. Command is correct\n";
  game.process("SHOW");

  return 0;
}