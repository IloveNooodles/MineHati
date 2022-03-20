compile-main:
	g++ -std=c++17 .\main.cpp .\Nontools.cpp .\Item.cpp  .\Inventory.cpp .\Tools.cpp .\Menu.cpp .\Crafting.cpp -o main

compile-item:
	g++ -std=c++17 .\main_item.cpp .\Item.cpp .\Tools.cpp .\Nontools.cpp -o main_item

item-run:
	.\main_item.exe

build-item-run: compile-item item-run

run:
	.\main.exe

all: compile-main run