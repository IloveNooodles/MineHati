#include "game.hpp"
using namespace std;

Game::Game() {
  this->menu = new Menu();
  this->gameEnd = false;
  this->items = new ItemsReader("../../config/item.txt");
  this->recipe = new RecipesReader("../../config/recipe");
  cout << "Loaded with default config\n"; 
}

Game::Game(string configPath) {
  this->menu = new Menu();
  this->gameEnd = false;
  this->items = new ItemsReader(configPath + "/item.txt");
  this->recipe = new RecipesReader(configPath + "/recipe");
  cout << "loaded with config located in " << configPath << "\n";
}

void Game::StartGame() {
  cout << "Welcome to the MineHati!\nType HELP to get started.\n\n";
  while (!gameEnd) {
    try {
      string command = askCommand();
      process(command);
    } catch (BaseException *e) {
      // Clear cin
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      // Output Exception
      e->what();
      cout << endl;
    }
  }
}

string Game::askCommand() {
  vector<string> available = {"EXPORT", "CRAFT",   "GIVE", "MOVE",    "USE",
                              "SHOW",   "DISCARD", "QUIT", "RECIPES", "HELP"};
  while (!this->gameEnd) {
    string command;
    cout << "Masukkan command: ";
    cin >> command;
    for (string com : available) {
      if (com == command) {
        return command;
      }
    }
    throw new InvalidCommandException(command);
  }
  return "GAME END";
}
void Game::process(string command) {
  if (command == "SHOW") {
    this->menu->Show();
    cout << endl;
  } else if (command == "DISCARD") {
    string slot;
    int qty;
    cin >> slot >> qty;
    this->menu->Discard(slot, qty);
  } else if (command == "USE") {
    string slot;
    cin >> slot;
    this->menu->Use(slot);
  } else if (command == "GIVE") {
    string name;
    int qty;
    cin >> name >> qty;
    this->menu->give(*this->items, name, qty);
  } else if (command == "MOVE") {
    string slot;
    int N;
    cin >> slot >> N;
    if (slot[0] == 'I') {
      vector<string> dest;
      for (int i = 0; i < N; i++) {
        string desSlot;
        cin >> desSlot;
        dest.push_back(desSlot);
      }
      if (dest[0][0] == 'I') {
        this->menu->MoveInventory(slot, dest[0]);
      } else if (dest[0][0] == 'C') {
        /* Pindah dari inventory ke inventory */
        this->menu->MoveToCraft(slot, N, dest);
      } else {
        throw new InvalidSlotIDException(dest[0]);
      }
    } else if (slot[0] == 'C') {
      /* Pindahkan crafting ke inventory */
      string dest;
      cin >> dest;
      this->menu->MoveFromCraft(slot, dest);
    }
  } else if (command == "CRAFT") {
    this->menu->Craft(*items, *recipe);
  } else if (command == "RECIPES") {
    this->menu->showRecipes(*this->recipe);
  } else if (command == "EXPORT") {
    string loc;
    cin >> loc;
    this->menu->exportInventory(*items, "./" + loc);
  } else if (command == "QUIT") {
    this->gameEnd = true;
    cout << "Thank you for playing MineHati!\n";
  } else if (command == "HELP") {
    cout << "\nAvailable commands:\n";
    cout << "SHOW: Show inventory and craft\n";
    cout << "DISCARD <INVENTORY_SLOT_ID> <QUANTITY>: Throw item in inventory with some quantity\n";
    cout << "USE <slot>: Use tool in inventory\n";
    cout << "GIVE <ITEM_NAME> <QUANTITY>: Give spesific item to with some quantity\n";
    cout << "MOVE <INVENTORY_SLOT_ID> N <CRAFT_SLOT_ID> / <INVENTORY_SLOT_ID> ...: Move item in craft and inventory\n";
    cout << "CRAFT: Use craft to make new item that available in the recipe\n";
    cout << "EXPORT <FILENAME>: Export inventory and craft into a file\n";
    cout << "RECIPES: See all available recipe\n";
    cout << "HELP: To see list of commands\n";
    cout << "QUIT: To exit the game\n\n";
  } else {
    throw new InvalidCommandException(command);
  }
}