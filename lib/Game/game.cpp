#include "game.hpp"
using namespace std;

Game::Game() {
    this->menu = new Menu();
    this->gameEnd = false;
    this->items = new ItemsReader("config/item.txt");
    this->recipe = new RecipesReader("config/recipe");
}

Game::Game(string configPath) {
  this->menu = new Menu();
  this->gameEnd = false;
  this->items = new ItemsReader(configPath + "/item.txt");
  this->recipe = new RecipesReader(configPath + "/recipe");
}

void Game::StartGame() {
    while(!gameEnd) {
        string command = askCommand();
        process(command);
    }
}
string Game::askCommand() {
    vector<string> available = {"EXPORT", "CRAFT", "GIVE", "MOVE", "USE", "SHOW", "DISCARD", "QUIT"};
    while (true) {
        string command;
        cout << "Masukkan command: ";
        cin >> command;
        for (string com : available) {
            if (com == command) {
                return command;
            }
        }
        throw new WrongCommandException(command);
    }
    return "GAME END";
}
void Game::process(string command) {
    if (command == "SHOW") {
        this->menu->Show();
        cout << endl;
    }
    else if (command == "DISCARD") {
        string slot; int qty;
        cin >> slot >> qty;
        this->menu->Discard(slot, qty);
    } 
    else if (command == "USE") {
        string slot;
        cin >> slot;
        this->menu->Use(slot);
    } 
    else if (command == "GIVE") {
      string name;
      int qty;
      cin >> name >> qty;
      this->menu->give(*this->items, name, qty);
    }
    else if (command == "MOVE") {
        string slot; int N;
        cin >> slot >> N;
        if (slot[0] == 'I') {
            vector<string> dest;
            for (int i = 0; i < N;i++) {
                string desSlot;
                cin >> desSlot;
                dest.push_back(desSlot);
            }
            if (dest[0][0] == 'I') {
                this->menu->MoveInventory(slot, dest[0]);
            } 
            else if (dest[0][0] == 'C') {
                /* Pindah dari inventory ke inventory */
                this->menu->MoveToCraft(slot, N, dest);
            }
            else {
                throw new SlotInputInvalidException(slot);
            }
        } 
        else if (slot[0] == 'C') {
            /* Pindahkan crafting ke inventory */
            string dest;
            cin >> dest;
            this->menu->MoveFromCraft(slot, dest);
        }
    } 
    else if (command == "CRAFT") {
        this->menu->Craft(*items, *recipe);
    } 
    else if (command == "EXPORT") {
        string loc;
        cin >> loc;
        this->menu->exportInventory(*items, "./" + loc);
    }
    else if (command == "QUIT") {
        this->gameEnd = true;
    }
}