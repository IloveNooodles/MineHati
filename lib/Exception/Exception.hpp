#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include "../Items/item.hpp"

#include <iostream>

using namespace std;

// Base Exception Class (Pure Virtual)
class BaseException {
public:
  virtual void what() = 0;
};

// IO Failed Exception Class
class IOException : public BaseException {
private:
  BaseException *exc;

public:
  void what() {
    cout << "IO Failed!" << endl;
    exc->what();
  }
};

// Command runtime exception
class CommandException : public BaseException {
private:
  BaseException *exc;
  string command;

public:
  CommandException(BaseException *exc, string command) {
    this->exc = exc;
    this->command = command;
  }

  void what() {
    cout << "Command " << command << " Failed!" << endl;
    exc->what();
  }
};

// General
class InvalidNumberException : public BaseException {
private:
  int number;

public:
  InvalidNumberException(int number) { this->number = number; }
  void what() { cout << this->number << " is an invalid number " << endl; }
};

// IO
class InvalidCommandException : public BaseException {
private:
  string command;

public:
  InvalidCommandException(string command) { this->command = command; }
  void what() { cout << this->command << " is an invalid command " << endl; }
};

class InvalidCommandArgsException : public BaseException {
private:
  string command;
  string args;

public:
  InvalidCommandArgsException(string command, string args) {
    this->command = command;
    this->args = args;
  }
  void what() {
    cout << this->args << " is an invalid args for command " << this->command
         << endl;
  }
};

class FileNotFoundException : public BaseException {
private:
  string fileName;

public:
  FileNotFoundException(string fileName) { this->fileName = fileName; }
  void what() { cout << this->fileName << " is not found " << endl; }
};

class WrongFileFormatException : public BaseException {
private:
  string fileName;

public:
  WrongFileFormatException(string fileName) { this->fileName = fileName; }
  void what() {
    cout << this->fileName << " is not in the correct format " << endl;
  }
};

// Item
class ItemNotFoundException : public BaseException {
private:
  string item;

public:
  ItemNotFoundException(string item) { this->item = item; }
  void what() { cout << this->item << " not found!" << endl; }
};

class WrongItemTypeException : public BaseException {
private:
  Item *item;

public:
  WrongItemTypeException(Item *item) { this->item = item; }
  void what() {
    string rightType = this->item->isTool() ? "nontool" : "tool";
    cout << "Item " << this->item->getName() << " is not a " << rightType << "!"
         << endl;
  }
};

class NotEnoughItemException : public BaseException {
private:
  Item *item;
  int needed;
  int available;

public:
  NotEnoughItemException(Item *item, int needed) {
    this->needed = needed;
    this->item = item;
    this->available = item->getQuantity();
  }
  void what() {
    cout << "Item " << this->item->getName() << " qty is less than "
         << this->needed << " (only available " << this->available << ")"
         << endl;
  }
};

class ItemStackOverflowException : public BaseException {
private:
  Item *item;
  int addedQuantity;

public:
  ItemStackOverflowException(Item *item, int addedQuantity) {
    this->item = item;
    this->addedQuantity = addedQuantity;
  }
  void what() {
    cout << "Item Stack " << this->item->getName() << " is full (currently "
         << this->item->getQuantity() << ") , cannot add "
         << this->addedQuantity << " more" << endl;
  }
};

class DifferentItemException : public BaseException {
private:
  Item *item1;
  Item *item2;

public:
  DifferentItemException(Item *item1, Item *item2) {
    this->item1 = item1;
    this->item2 = item2;
  }
  void what() {
    cout << "Item " << this->item1->getName() << " is different from "
         << this->item2->getName() << endl;
  }
};

// Crafting
class NoRecipeFoundException : public BaseException {
public:
  NoRecipeFoundException() {}
  void what() { cout << "No recipe found for this combination!"; }
};

// Slot
class InventoryFullException : public BaseException {
public:
  InventoryFullException() {}
  void what() { cout << "Inventory is full!" << endl; }
};

class InvalidSlotIDException : public BaseException {
private:
  string slot;

public:
  InvalidSlotIDException(string slot) { this->slot = slot; }
  void what() { cout << "Invalid slot ID " << this->slot << endl; }
};

class EmptySlotException : public BaseException {
private:
  string slot;

public:
  EmptySlotException(string slot) { this->slot = slot; }
  void what() { cout << "Slot " << this->slot << " is empty!" << endl; }
};

class SlotIsOccupiedException : public BaseException {
private:
  string slot;

public:
  SlotIsOccupiedException(string slot) { this->slot = slot; }
  void what() {
    cout << "Slot " << this->slot << " is already occupied!" << endl;
  }
};

/* Game */
class WrongCommandException : public BaseException {
private:
  string command;
public:
  WrongCommandException(string command) {
    this->command = command;
  }
  void what() {
    cout << this->command << " is an invalid command!" << endl;
  }
};

class SlotInputInvalidException : public BaseException {
private:
  string slot;
public:
  SlotInputInvalidException(string slot) {
    this->slot = slot;
  }
  void what() {
    cout << this->slot << " is an invalid slot!" << endl;
  }
};

#endif