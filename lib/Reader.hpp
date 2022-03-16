#ifndef __READER_HPP__
#define __READER_HPP__
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Recipe {
  private:
    int rows;
    int cols;
    vector<vector<string>> recipe;
    string name;
    int amount;
  public:
    Recipe(int rows, int cols, vector<vector<string>> recipe, string name, int amount) {
      this->rows = rows;
      this->cols = cols;
      this->recipe = recipe;
      this->name = name;
      this->amount = amount;
    }
    string getName() {
      return this->name;
    }
    int getAmount() {
      return this->amount;
    }
    int getRows() {
      return this->rows;
    }
    int getCols() {
      return this->cols;
    }
    vector<vector<string>> getRecipe() {
      return this->recipe;
    }
};

class RecipesReader {
  private:
    vector<Recipe> recipes;
  public:
    RecipesReader() {
      for (const auto & file : fs::directory_iterator("./config/recipe")) {
        /* Baca file, simpan property Recipenya */
        ifstream inFile;
        inFile.open(file.path());
        int rows; int cols;
        inFile >> rows >> cols;
        vector<vector<string>> recipe;
        for (int i = 0; i < rows; i ++) {
          vector<string> tmp;
          for (int j = 0; j < cols; j ++) {
            string r;
            inFile >> r;
            tmp.push_back(r);
          }
          recipe.push_back(tmp);
        }
        string name; int qty;
        inFile >> name >> qty;
        inFile.close();
        /* Masukkan recipe ke recipes */
        Recipe r(rows, cols, recipe, name, qty);
        recipes.push_back(r);
      }
    }
    vector<Recipe> getRecipes() {
      return recipes;
    }
};

class ItemsReader {
  private:
    map <string, int> idMap;
    map <string, string> typeMap;
    map <string, string> ctgMap;
  public:
    ItemsReader() {
      ifstream inFile;
      inFile.open("./config/item.txt");
      int id; string name; string type; string ctg;
      while (inFile >> id >> name >> type >> ctg) {
        this->idMap[name] = id;
        this->typeMap[name] = type;
        this->ctgMap[name] = ctg;
      }
      inFile.close();
    }
    int getID(string name) {
      return this->idMap[name];
    }
    string getType(string name) {
      return this->typeMap[name];
    }
    string getCtg(string name) {
      return this->ctgMap[name];
    }
};
#endif