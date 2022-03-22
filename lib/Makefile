compile-main:
	g++ -std=c++17 ./main.cpp ./Items/nontools.cpp ./Items/item.cpp ./Items/tools.cpp ./Menu/menu.cpp -o main

compile-item:
	g++ -std=c++17 .\main_item.cpp .\Item.cpp .\Tools.cpp .\Nontools.cpp -o main_item

item-run:
	.\main_item.exe

build-item-run: compile-item item-run

run:
	.\main.exe

all: compile-main run