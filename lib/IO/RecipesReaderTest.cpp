#include "RecipesReader.hpp"

int main() {
  RecipesReader r("../../config/recipe");
  vector<Recipe> recipes = r.getRecipes();
  for (Recipe recipe : recipes) {
    cout << "=====================================" << endl;
    cout << recipe.getName() << endl;
    cout << recipe.getAmount() << endl;
    cout << recipe.getRows() << endl;
    cout << recipe.getCols() << endl;
    for (int i = 0; i < recipe.getRows(); i ++) {
      for (int j = 0; j < recipe.getCols(); j ++) {
        cout << recipe.getRecipe()[i][j] << " ";
      }
      cout << endl;
    }
  }
}