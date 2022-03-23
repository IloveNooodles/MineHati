#ifndef __ITEMREADER_HPP_
#define __ITEMREADER_HPP_
#include "../Exception/Exception.hpp"
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class ItemsReader {
private:
  map<string, int> idMap;
  map<string, string> typeMap;
  map<string, string> ctgMap;

public:
  ItemsReader(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
      throw new FileNotFoundException(fileName);
    }
    int id;
    string name;
    string type;
    string ctg;
    while (inFile >> id >> name >> type >> ctg) {
      this->idMap[name] = id;
      this->typeMap[name] = type;
      this->ctgMap[name] = ctg;
    }
    inFile.close();
  }
  int getID(string name) { return this->idMap[name]; }
  string getType(string name) { return this->typeMap[name]; }
  string getCtg(string name) { return this->ctgMap[name]; }
};

#endif