# Mine Hati

MineHati is a minecraft-like CLI game made using C++ that applies Object Oriented Programming (OOP) Paradigm. This project was made to fulfull Tubes 1 Object Oriented Programming 2022. Several concept implementation of OOP is Polymorphism, Inheritance, Abstract Base Class, Method and Operator Overloading, and Template & Generics. This project also includes exception handling and STL library for its algorithm. 

## Authors

| Nama                           | NIM      |
| ------------------------------ | -------- |
| Muhammad Garebaldhie ER Rahman | 13520029 |
| Rifqi Naufal Abdjul            | 13520062 |
| Muhammad Naufal Satriandana    | 13520068 |
| Aira Thalca Avila Putra        | 13520101 |
| Marchotridyo                   | 13520119 |

## General Infornation & Features
MineHati focused on Mobita who bored because of the pandemic. To amuse Mobita, Doraemongais made a minecraft-like game for Mobita to get rid of the boredom. MineHati provide an Inventory to SHOW all of the items that Moibta currenly has, Crafting Table to make an item with spesific recipe, and Items that categorized as Tool or Nontool that varies from WOOD to a DIAMOND SWORD.

## Screenshot

## Program Requirements
1. [GCC 7 or higher (that support c++17)](https://gcc.gnu.org/install/binaries.html)
2. [Makefile (GNU Make)](https://www.gnu.org/software/make/)

To run this program in any operating system, you must have gcc that support c++17 installed in your OS and also Makefile to compile manually or you can just run the provided binary/exe file.

## How to build
1. Clone the directory using `git clone https://github.com/IloveNooodles/MineHati.git`
1. Move to the directory using `cd` command
1. In the program directory run `make compile run` to run the program
1. After compiling, the program should appear in current directory
1. run `./main` to run the program

## Usage
After run the program there are several commands that you could do. Type HELP to print all of the available commands
1. SHOW: Show inventory and craft
1. DISCARD <INVENTORY_SLOT_ID> <QUANTITY>: Throw item in inventory with some quantity
1. USE <slot>: Use tool in inventory\n";
1. GIVE <ITEM_NAME> <QUANTITY>: Give spesific item to with some quantity\n";
1. MOVE <INVENTORY_SLOT_ID> N <CRAFT_SLOT_ID> / <INVENTORY_SLOT_ID> ...: Move item in craft and inventory
1. CRAFT: Use craft to make new item that available in the recipe
1. EXPORT <FILENAME>: Export inventory and craft into a file
1. RECIPES: See all available recipe
1. HELP: To see list of commands
1. QUIT: To exit the game

## Room for improvement
1. Make a GUI for the program for ease of use
1. Add more items and recipe to get more minecraft experience

### copyright
