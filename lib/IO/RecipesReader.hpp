#ifndef __RECIPESREADER_HPP__
#define __RECIPESREADER_HPP__
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

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
  Recipe(int rows, int cols, vector<vector<string>> recipe, string name,
         int amount) {
    this->rows = rows;
    this->cols = cols;
    this->recipe = recipe;
    this->name = name;
    this->amount = amount;
  }
  string getName() { return this->name; }
  int getAmount() { return this->amount; }
  int getRows() { return this->rows; }
  int getCols() { return this->cols; }
  vector<vector<string>> getRecipe() { return this->recipe; }
};

class RecipesReader {
private:
  vector<Recipe> recipes;

public:
  RecipesReader(string fileDir) {
    try {
      for (const auto &file : fs::directory_iterator(fileDir)) {
        /* Baca file, simpan property Recipenya */
        ifstream inFile;
        inFile.open(file.path());
        int rows;
        int cols;
        inFile >> rows >> cols;
        vector<vector<string>> recipe;
        for (int i = 0; i < rows; i++) {
          vector<string> tmp;
          for (int j = 0; j < cols; j++) {
            string r;
            inFile >> r;
            if (r == "\x00") {
              throw new WrongFileFormatException(file.path());
            }
            tmp.push_back(r);
          }
          recipe.push_back(tmp);
        }
        string name;
        int qty;
        inFile >> name >> qty;
        inFile.close();
        /* Masukkan recipe ke recipes */
        Recipe r(rows, cols, recipe, name, qty);
        recipes.push_back(r);
      }
    } catch (const fs::filesystem_error &e) {
      throw new FileNotFoundException(fileDir);
    }
  }
  vector<Recipe> getRecipes() { return recipes; }
};
#endif