#ifndef __BASE_EXCEPTION_HPP_
#define __BASE_EXCEPTION_HPP_

#include <iostream>
using namespace std;

class BaseException
{
public:
  virtual void what() = 0;
};

class CraftingFailedException : public BaseException
{
private:

public:
  CraftingFailedException()
  {
  }
  void what()
  {
    cout << "Crafting failed!" << endl;
  }
};

class PlacingFailedException : public BaseException
{
private:

public:
  PlacingFailedException()
  {
  }
  void what()
  {
    cout << "Move failed!" << endl;
  }
};

class InventoryFailedException : public BaseException
{
private:

public:
  InventoryFailedException(BaseException *exc)
  {
  }
  void what()
  {
  }
};

class NoRecipeFoundException : public BaseException
{
  /* ini udah termasuk yang klo itemnya beda */
private:
  // Recipe recipe;
  // Crafting c;
public:
  NoRecipeFoundException();
  void what()
  {
    cout << "No recipe found for this combination!";
  }
};

class NoItemInSlotException : public BaseException
{
private:
  /* item a */
  /* inventory i*/
  /* craft c*/
  /* int src*/
  /* int dsc*/
public:
  NoItemInSlotException();
  void what()
  {
    // cout << "No item" << a << "in" << /* src */ << endl;
  }
};

class InvalidNumberException : public BaseException
{
private:
  int number;

public:
  InvalidNumberException(int number)
  {
    this->number = number;
  }
  void what()
  {
    cout << this->number << "is non positive integer" << endl;
  }
};

class IdNotFoundException : public BaseException
{
private:
  int id;

public:
  IdNotFoundException(int id)
  {
    this->id = id;
  }
  void what()
  {
    cout << "Id " << this->id << " was not found";
  }
};

class NotEnoughItemException : public BaseException
{
private:
  /* item  i*/
  int qty;

public:
  NotEnoughItemException(int qty)
  {
    this->qty = qty;
  }
  void what()
  {
    cout << "Item" /* item */ << "diambil sebanyak" << this->qty << "Available" /* item i . getquantitiy*/ << endl;
  }
};

class ItemStackException : public BaseException
{
private:
  /* inventory i */
  /* item it */
  /* int positition */
public:
  ItemStackException();
  void what()
  {
    cout << "Item pada posisi position tidak bisa di tumpuk " << endl;
  }
};

class QuantitiyException : public BaseException
{
private:
  // inventory i
  // item it
  int qty;
  // int position
public:
  QuantitiyException(int qty)
  {
    this->qty = qty;
  }
  void what()
  {
    cout << "Max quantitiy (64) found " << this->qty << endl;
  }
};

class ItemNotFoundException : public BaseException
{
private:
  // Item it;
public:
  // ItemNotFoundException(Item it);
  void what()
  {
    cout << "This item is not available" << endl;
  }
};

class MoveException : public BaseException
{
private:
  int src;
  int dsc;
  // inventory i
public:
  MoveException(int src, int dsc)
  {
    this->src = src;
    this->dsc = dsc;
  }
  void what()
  {
    cout << "Item pada" << this->src << "Memiliki jenis yang berbeda dengan" << this->dsc;
  }
};

#endif