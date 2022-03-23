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
}

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
}

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
    cout << this->args << " is an invalid args for command " this->command
         << endl;
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

// Crafting
class NoRecipeFoundException : public BaseException {
public:
  NoRecipeFoundException();
  void what() { cout << "No recipe found for this combination!"; }
};

// Slot
class InventoryFullException : public BaseException {
public:
  InventoryFullException();
  void what() { cout << "Inventory is full!" << endl; }
};

class InvalidSlotIDException : public BaseException {
private:
  string slot;

public:
  InvalidSlotIDException(string slot) { this->slot = slot; }
  void what() { cout << "Invalid slot id " << this->slot << endl; }
};

class NoItemInSlotException : public BaseException {
private:
  Item *item;
  string slot;

public:
  NoItemInSlotException(Item *item, string slot) {
    this->item = item;
    this->slot = slot;
  }
  void what() {
    cout << "No item " << this->item->getName() << " in " << this->slot << endl;
  }
};

class NotEnoughItemException : public BaseException {
private:
  Item *item;
  int needed;
  int available;

public:
  NotEnoughItemException(Item *item, int needed, int available) {
    this->needed = needed;
    this->item = item;
    this->available = available;
  }
  void what() {
    cout << "Item " << this->item->getName() << " qty is less than "
         << this->needed << " (only available " << this->available << ")"
         << endl;
  }
};

class EmptySlotException : public BaseException {
private:
  string slot;

public:
  EmptySlotException(string slot) { this->slot = slot; }
  void what() { cout << "Slot " << this->slot << " is empty!" << endl; }
};
#endif