#include "Item.hpp"

Item::Item()
{
  this->id = -999;
  this->name = "-";
  this->category = "-";
}
Item::Item(int id,string nama, string jenis) {
  this->id = id;
  this->name = nama;
  this->category = jenis;
}
Item::Item(int id,string nama) {
  this->id = id;
  this->name = nama;
  this->category = "-";
}
int Item::getId() const
{
  return this->id;
}
void Item::setId(int id)
{
  this->id = id;
}
string Item::getName() const
{
  return this->name;
}
void Item::setName(string name)
{
  this->name = name;
}
string Item::getCategory() const
{
  return this->category;
}
void Item::setCategory(string category)
{
  this->category = category;
}