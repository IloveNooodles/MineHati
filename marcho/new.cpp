#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class ItemsReader {
  private:
    map <string, int> idMap;
    map <string, string> typeMap;
    map <string, string> ctgMap;
  public:
    ItemsReader() {
      ifstream inFile;
      inFile.open("./item.txt");
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
};

int main() {
  Inventory i;
  Crafting c;
  ItemsReader items;
  
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
    }
  }
  return 0;
}