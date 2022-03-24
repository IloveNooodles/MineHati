// // sample main file, replace this with your own code
// #include <filesystem>
// #include <fstream>
// #include <iostream>
// #include <string>

// using namespace std;

// int main()

// {
//   string configPath = "./config";
//   string itemConfigPath = configPath + "/item.txt";

//   // read item from config file
//   ifstream itemConfigFile(itemConfigPath);

//   for (string line; getline(itemConfigFile, line);)
//   {
//     cout << line << endl;
//     // do something
//   }

//   // read recipes

//   for (const auto &entry : filesystem::directory_iterator(configPath + "/recipe"))
//   {
//     cout << entry.path() << endl;
//     // read from file and do something
//   }

//   // sample interaction

//   string command;
//   while (cin >> command)
//   {
//     if (command == "EXPORT")
//     {
//       string outputPath;
//       cin >> outputPath;
//       ofstream outputFile(outputPath);

//       // hardcode for first test case
//       outputFile << "21:10" << endl;
//       outputFile << "6:1" << endl;

//       for (int i = 2; i < 27; i++)

//       {

//         outputFile << "0:0" << endl;
//       }

//       cout << "Exported" << endl;
//     }
//     else if (command == "CRAFT")
//     {
//       cout << "TODO" << endl;
//     }
//     else if (command == "GIVE")
//     {
//       string itemName;

//       int
//           itemQty;
//       cin >> itemName >> itemQty;
//       cout << "TODO" << endl;
//     }
//     else if (command == "MOVE")
//     {
//       string slotSrc;
//       int slotQty;
//       string slotDest;
//       // need to handle multiple destinations
//       cin >> slotSrc >> slotQty >> slotDest;
//       cout << "TODO" << endl;
//     }
//     else
//     {
//       // todo
//       cout << "Invalid command" << endl;
//     }
//   }
//   return 0;
// }

#include "lib/Game/game.hpp"

int main()
{
    Game game;
    game.StartGame();
    return 0;
  // Menu *ayam = new Menu();
  // ItemsReader items;
  // RecipesReader recipes;
  // ayam->give(items, "OAK_LOG", 41);
  // ayam->give(items, "DIAMOND", 8);
  // ayam->give(items, "OAK_LOG", 25);
  // ayam->give(items, "DIAMOND_AXE", 11, 7);
  // ayam->Show();
  // cout<<endl;
  // string dest[4] = {"C2", "C1", "C5", "C1"};
  // string dest2[2] = {"C4", "C7"};
  // ayam->MoveToCraft("I1", 4, dest);
  // ayam->MoveToCraft("I4", 1, dest2);
  // ayam->Show();
  // cout<<endl;
  // ayam->MoveFromCraft("C2", "I1");
  // ayam->MoveFromCraft("C1", "I20");
  // ayam->MoveFromCraft("C1", "I20");
  // ayam->MoveFromCraft("C4", "I26");
  // ayam->Show();
  // cout<<endl;
  // ayam->MoveInventory("I0","I2");
  // ayam->Discard("I2",12);
  // ayam->Use("I3");
  // ayam->MoveFromCraft("C5", "I1");
  // ayam->Show();
  // cout<<endl;
  // ayam->MoveToCraft("I3", 1, dest);
  // ayam->MoveToCraft("I5", 1, dest2);
  // ayam->Show();
  // cout<<endl;
  // ayam->Craft(items, recipes);
  // ayam->give(items, "STICK", 11);
  // ayam->Show();
  // cout<<endl;
  // ayam->MoveToCraft("I1", 3, dest);
  // ayam->MoveToCraft("I4", 2, dest2);
  // ayam->Show();
  // cout<<endl;
  // ayam->Craft(items, recipes);
  // ayam->Show();
  // cout<<endl;
  
}