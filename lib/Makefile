compile-main:
	g++ -std=c++17 .\main.cpp .\Items\Nontools.cpp .\Items\Item.cpp .\Items\Tools.cpp .\Menu\Menu.cpp -o main

compile-item:
	g++ -std=c++17 .\main_item.cpp .\Item.cpp .\Tools.cpp .\Nontools.cpp -o main_item

item-run:
	.\main_item.exe

build-item-run: compile-item item-run

run:
	.\main.exe

all: compile-main run