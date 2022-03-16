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

class Item {
  protected:
    string nama;
    string jenis;
    int qty;
  public:
    Item(string nama, string jenis, int qty) {
      this->nama = nama;
      this->jenis = jenis;
      this->qty = qty;
    }
    Item(string nama, int qty) {
      this->nama = nama;
      this->jenis = "-";
      this->qty = qty;
    }
    Item() {
      this->nama = "-";
      this->jenis = "-";
      this->qty = -1;
    }
    string getName() {
      return this->nama;
    }
    string getType() {
      return this->jenis;
    }
    int getQty() {
      return this->qty;
    }
    void addQty(int qty) {
      this->qty += qty;
    }
    virtual bool isNontool() { return false; }
    virtual bool isTool() { return false; }
    virtual int getDura() { return -1; }
    virtual void decreaseDura(int dura) { }
};

class Nontool : public Item {
  public:
    Nontool(string nama, string jenis, int qty) : Item(nama, jenis, qty) {}
    Nontool(string nama, int qty) : Item(nama, qty) {}
    bool isNontool() {
      return true;
    }
};

class Tool : public Item {
  private:
    int durability;
  public:
    Tool(string nama, int durability) : Item(nama, 1) {
      this->durability = durability;
    }
    bool isTool() {
      return true;
    }
    int getDura() {
      return this->durability;
    }
    void decreaseDura(int dura) {
      this->durability -= dura;
    }
};


class Crafting {
  private:
    friend class Nontool;
    friend class Tool;
    vector<vector<Item*>> cMatrix;
  public:
    Crafting() {
      for (int i = 0; i < 3; i ++) {
        vector<Item*> tmp;
        for (int j = 0; j < 3; j ++) {
          tmp.push_back(new Item());
        }
        cMatrix.push_back(tmp);
      }
    }
    void emptyCrafting() {
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          if (cMatrix[i][j]->getName() != "-") {
            cMatrix[i][j] = new Item();
          }
        }
      }
    }
    void print() {
      int slot = 0;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          if (cMatrix[i][j]->getName() != "-") {
            if (cMatrix[i][j]->isNontool()) {
              cout << "[C" << setw(2) << slot << "> " << cMatrix[i][j]->getName() << ":" << cMatrix[i][j]->getQty() << "] ";
            } else {
              cout << "[C" << setw(2) << slot << "> " << cMatrix[i][j]->getName() << ":" << cMatrix[i][j]->getDura() << "/10] ";
            }
          } else {
            cout << "[C" << setw(2) << slot << "> EMPTY] ";
          }
          slot ++;
        }
        cout << endl;
      }
    }
    void setMatrix(int i, int j, Item* value) {
      cMatrix[i][j] = value;
    }
    Item* getElement(int i, int j) {
      return cMatrix[i][j];
    }
    int getCraftingRows() {
      int minRow = 999;
      int maxRow = -999;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          if (cMatrix[i][j]->getName() != "-") {
            if (i + 1 < minRow) {
              minRow = i + 1;
            }
            if (i + 1 > maxRow) {
              maxRow = i + 1;
            }
          }
        }
      }
      return (maxRow == -999) ? 0 : maxRow - minRow + 1;
    }
    int getCraftingCols() {
      int minCol = 999;
      int maxCol = -999;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          if (cMatrix[i][j]->getName() != "-") {
            if (j + 1 < minCol) {
              minCol = j + 1;
            }
            if (j + 1 > maxCol) {
              maxCol = j + 1;
            }
          }
        }
      }
      return (maxCol == -999) ? 0 : maxCol - minCol + 1;
    }
};

class Inventory {
  private:
    vector<vector<Item*>> invMatrix;
  public:
    Inventory() {
      for (int i = 0; i < 3; i ++) {
        vector<Item*> tmp;
        for (int j = 0; j < 9; j ++) {
          tmp.push_back(new Item());
        }
        invMatrix.push_back(tmp);
      }
    }
    void print() {
      int slot = 0;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++) {
          if (invMatrix[i][j]->getName() != "-") {
            if (invMatrix[i][j]->isNontool()) {
              cout << "[I" << setw(2) << slot << "> " << invMatrix[i][j]->getName() << ":" << invMatrix[i][j]->getQty() << "] ";
            } else {
              cout << "[I" << setw(2) << slot << "> " << invMatrix[i][j]->getName() << ":" << invMatrix[i][j]->getDura() << "/10] ";
            }
          } else {
            cout << "[I" << setw(2) << slot << "> EMPTY] ";
          }
          slot ++;
        }
        cout << endl;
      }
    }
    void give(ItemsReader& items, string name, int qty, int dura) {
      if (items.getCtg(name) == "TOOL") {
        /* Cari slot untuk dimasukkan tool */
        int i = 0;
        while (i < 3 && qty > 0) {
          int j = 0;
          while (j < 9 && qty > 0) {
            if (invMatrix[i][j]->getName() == "-") {
              invMatrix[i][j] = new Tool(name, dura);
              qty --;
            }
            j ++;
          }
          i ++;
        }
      }
    }
    void give(ItemsReader& items, string name, int qty) {
      if (items.getCtg(name) == "TOOL") {
        /* Cari slot untuk dimasukkan tool */
        int i = 0;
        while (i < 3 && qty > 0) {
          int j = 0;
          while (j < 9 && qty > 0) {
            if (invMatrix[i][j]->getName() == "-") {
              invMatrix[i][j] = new Tool(name, 10);
              qty --;
            }
            j ++;
          }
          i ++;
        }
      } else if (items.getCtg(name) == "NONTOOL") {
        /* Cari slot yang sudah ada untuk dimasukkan nontool */
        int i = 0;
        while (i < 3 && qty > 0) {
          int j = 0;
          while (j < 9 && qty > 0) {
            if (invMatrix[i][j]->getName() == name) {
              if (qty + invMatrix[i][j]->getQty() <= 64) {
                invMatrix[i][j]->addQty(qty);
                qty = 0;
              } else {
                int sisa = 64 - invMatrix[i][j]->getQty();
                invMatrix[i][j]->addQty(sisa);
                qty -= sisa;
              }
            }
            j ++;
          }
          i ++;
        }
        /* Cari slot yang kosong untuk dimasukkan nontool */
        i = 0;
        while (i < 3 && qty > 0) {
          int j = 0;
          while (j < 9 && qty > 0) {
            if (invMatrix[i][j]->getName() == "-") {
              if (qty <= 64) {
                invMatrix[i][j] = new Nontool(name, items.getType(name), qty);
                qty = 0;
              } else {
                invMatrix[i][j] = new Nontool(name, items.getType(name), 64);
                qty -= 64;
              }
            }
            j ++;
          }
          i ++;
        }
      }
    }
    void discard(int slot, int qty) {
      /* Cari row dan col yang bersesuaian dengan slot */
      int i, j;
      j = slot % 9;
      i = slot / 9;
      /* Kurangi quantity item sebanyak qty */
      invMatrix[i][j]->addQty(-1 * qty);
      if (invMatrix[i][j]->getQty() == 0) {
        /* Hapus dari invMatrix */
        invMatrix[i][j] = new Item();
      }
    }
    void use(int slot) {
      /* Cari row dan col yang bersesuaian dengan slot */
      int i, j;
      j = slot % 9;
      i = slot / 9;
      /* Kurangi durability sebanyak 1 */
      invMatrix[i][j]->decreaseDura(1);
      if (invMatrix[i][j]->getDura() <= 0) {
        /* Hapus dari invMatrix */
        invMatrix[i][j] = new Item();
      }
    }
    void moveToCraft(ItemsReader& items, Crafting& c, int slot, int dest) {
      int i, j; /* Index untuk inventory */
      j = slot % 9;
      i = slot / 9;
      int k, l; /* Index untuk crafting */
      l = dest % 3;
      k = dest / 3;
      /* Lihat inventory yang akan diambil */
      if (items.getCtg(invMatrix[i][j]->getName()) == "TOOL") {
        /* Jika tool, */
        c.setMatrix(k, l, invMatrix[i][j]);
        invMatrix[i][j] = new Item();
      } else {
        /* Jika nontool, */
        string name = invMatrix[i][j]->getName();
        c.setMatrix(k, l, new Nontool(name, items.getType(name), 1));
        invMatrix[i][j]->addQty(-1);
        if (invMatrix[i][j]->getQty() == 0) {
          invMatrix[i][j] = new Item();
        }
      }
    }
    void moveToInventory(int slot, int dest) {
      int i, j; /* Index untuk src */
      j = slot % 9;
      i = slot / 9;
      int k, l; /* Index untuk dest */
      k = dest % 9;
      l = dest / 9;
      int sisa = 64 - invMatrix[k][l]->getQty();
      if (invMatrix[i][j]->getQty() <= sisa) {
        /* invMatrix[i][j] habis */
        invMatrix[k][l]->addQty(invMatrix[i][j]->getQty());
        invMatrix[i][j] = new Item();
      } else {
        invMatrix[k][l]->addQty(sisa);
        invMatrix[i][j]->addQty(-1 * sisa);
      }
    }
    void moveFromCraft(ItemsReader& items, Crafting& c, int slot, int dest) {
      int i, j; /* Index untuk crafting */
      j = slot % 3;
      i = slot / 3;
      int k, l; /* Index untuk inventory */
      l = dest % 9;
      k = dest / 9;
      string name = c.getElement(i, j)->getName();
      if (items.getCtg(name) == "TOOL") {
        /* Jika tool, */
        invMatrix[k][l] = c.getElement(i, j);
      } else {
        /* Jika bukan tool, */
        /* Cek apakah sudah diisi oleh item */
        if (invMatrix[k][l]->getName() != "-") {
          /* Tambahkan qty sebanyak 1 */
          invMatrix[k][l]->addQty(1);
        } else {
          /* Buat baru dengan qty 1 */
          invMatrix[k][l] = new Nontool(name, items.getType(name), 1);
        }
      }
      c.setMatrix(i, j, new Item());
    }
    void doCrafting(ItemsReader& items, RecipesReader& recipes, Crafting& c) {
      vector<Recipe> r = recipes.getRecipes();
      bool recipeFound = false;
      /* Cek apakah tipe yang harus membenarkan atau tidak */
      bool fixedItem = false;
      int itemCount = 0; /* Banyak non tool */
      int itemDura[] = {-1, -1};
      string itemName[] = {"-", "-"};
      for (int i = 0; i < 3 && itemCount < 2; i ++) {
        for (int j = 0; j < 3 && itemCount < 2; j ++) {
          string name = c.getElement(i, j)->getName();
          if (name != "-") {
            if (items.getCtg(name) == "TOOL") {
              itemDura[itemCount] = c.getElement(i, j)->getDura();
              itemName[itemCount] = c.getElement(i, j)->getName();
              itemCount ++;
            } else {
              itemCount += 999; /* Agar keluar dari loop */
            }
          }
        }
      }
      if (itemCount == 2) {
        if (itemName[0] == itemName[1]) {
          /* Boleh melakukan fix */
          fixedItem = true;
        }
      }
      if (fixedItem) {
        /* Yang dilakukan adalah memperbaiki item */
        int dura = (itemDura[0] + itemDura[1] > 10 ? 10 : itemDura[0] + itemDura[1]);
        give(items, itemName[0], 1, dura);
        c.emptyCrafting();
      } else {
        /* Cek setiap resep yang ada di recipe */
        for (int x = 0; x < r.size(); x ++) {
          vector<vector<string>> recipe = r[x].getRecipe();
          int rows = r[x].getRows();
          int cols = r[x].getCols();
          if (rows != c.getCraftingRows() || cols != c.getCraftingCols()) {
            continue;
          }
          /* Looping pada matrix c */
          bool foundDifferent = false;
          for (int i = 0; i < 3 - rows + 1 && !recipeFound; i ++) {
            for (int j = 0; j < 3 - cols + 1 && !recipeFound; j ++) {
              foundDifferent = false;
              for (int k = 0; k < rows && !foundDifferent; k ++) {
                for (int l = 0; l < cols && !foundDifferent; l ++) {
                  if (c.getElement(i + k, j + l)->getName() != "-") {
                    string type = items.getType(c.getElement(i + k, j + l)->getName());
                    if (type != "-") {
                      /* Ada tipenya */
                      foundDifferent = type != recipe[k][l];
                    } else {
                      /* Tidak ada tipenya */
                      foundDifferent = c.getElement(i + k, j + l)->getName() != recipe[k][l];
                    }
                  } else {
                    foundDifferent = c.getElement(i + k, j + l)->getName() != recipe[k][l];
                  }
                }
              }
              /* k dan l out of range atau foundDifferent = true */
              if (!foundDifferent) {
                recipeFound = true; 
              }
            }
          }

          if (recipeFound) {
            c.emptyCrafting();
            give(items, r[x].getName(), r[x].getAmount());
          }
        }
      }
      if (!recipeFound && !fixedItem) {
        /* Nanti ganti pakai exception */
        cout << ">> Gagal melakukan crafting." << endl;
      }
    }
    void exportInventory(ItemsReader& items, string loc) {
      ofstream file;
      file.open(loc);
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++) {
          string name = invMatrix[i][j]->getName();
          if (name == "-") {
            file << "0:0\n";
          } else {
            if (items.getCtg(name) == "TOOL") {
              file << items.getID(name) << ":" << invMatrix[i][j]->getDura() << endl;
            } else {
              file << items.getID(name) << ":" << invMatrix[i][j]->getQty() << endl;
            }
          }
        }
      }
      file.close();
    }
};

int main() {
  Inventory i;
  Crafting c;
  ItemsReader items;
  RecipesReader recipes;
  
  while (true) {
    cout << "> ";
    string input;
    cin >> input;
    if (input == "SHOW") {
      cout << "CRAFTING TABLE:" << endl;
      c.print();
      cout << "INVENTORY:" << endl;
      i.print();
    } else if (input == "GIVE") {
      string name; int qty;
      cin >> name >> qty;
      i.give(items, name, qty);
    } else if (input == "DISCARD") {
      string slot; int qty;
      cin >> slot >> qty;
      int iSlot = stoi(slot.substr(1));
      i.discard(iSlot, qty);
    } else if (input == "USE") {
      string slot;
      cin >> slot;
      int iSlot = stoi(slot.substr(1));
      i.use(iSlot);
    } else if (input == "MOVE") {
      string slot; int N;
      cin >> slot >> N;
      int iSlot = stoi(slot.substr(1));
      if (slot[0] == 'I') {
        while (N --) {
          string dest;
          cin >> dest;
          int destSlot = stoi(dest.substr(1));
          if (dest[0] == 'C') {
            /* Pindahkan inventory ke crafting */
            i.moveToCraft(items, c, iSlot, destSlot);
          } else {
            /* Pindah dari inventory ke inventory */
            i.moveToInventory(iSlot, destSlot);
          }
        }
      } else {
        /* Pindahkan crafting ke inventory */
        string dest;
        cin >> dest;
        int destSlot = stoi(dest.substr(1));
        i.moveFromCraft(items, c, iSlot, destSlot);
      }
    } else if (input == "CRAFT") {
      i.doCrafting(items, recipes, c);
    } else if (input == "EXPORT") {
      string loc;
      cin >> loc;
      i.exportInventory(items, "./" + loc);
    }
  }
  return 0;
}