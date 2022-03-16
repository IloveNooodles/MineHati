#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string getJenisFromNama(string nama) {
  /* Sementara hardcoded, nanti pakai map aja ya */
  if (nama == "OAK_LOG") {
    return "LOG";
  } else if (nama == "SPRUCE_LOG") {
    return "LOG";
  } else if (nama == "BIRCH_LOG") {
    return "LOG";
  } else if (nama == "OAK_PLANK") {
    return "PLANK";
  } else if (nama == "SPRUCE_PLANK") {
    return "PLANK";
  } else if (nama == "BIRCH_PLANK") {
    return "PLANK";
  } else if (nama == "STICK") {
    return "STICK";
  } else if (nama == "COBBLESTONE") {
    return "STONE";
  } else if (nama == "BLACKSTONE") {
    return "STONE";
  } else if (nama == "IRON_INGOT") {
    return "IRON_INGOT";
  } else if (nama == "IRON_NUGGET") {
    return "IRON_NUGGET";
  } else if (nama == "DIAMOND") {
    return "DIAMOND";
  } else if (nama == "WOODEN_PICKAXE") {
    return "PICKAXE";
  } else if (nama == "STONE_PICKAXE") {
    return "PICKAXE";
  } else if (nama == "IRON_PICKAXE") {
    return "PICKAXE";
  } else if (nama == "DIAMOND_PICKAXE") {
    return "PICKAXE";
  } else if (nama == "WOODEN_AXE") {
    return "AXE";
  } else if (nama == "STONE_AXE") {
    return "AXE";
  } else if (nama == "IRON_AXE") {
    return "AXE";
  } else if (nama == "DIAMOND_AXE") {
    return "AXE";
  } else if (nama == "WOODEN_SWORD") {
    return "SWORD";
  } else if (nama == "STONE_SWORD") {
    return "SWORD";
  } else if (nama == "IRON_SWORD") {
    return "SWORD";
  } else if (nama == "DIAMOND_SWORD") {
    return "SWORD";
  }
  return "N/A";
}
string getVariasiFromNama(string nama) {
  /* Sementara hardcoded, nanti pakai map aja ya */
  if (nama == "OAK_LOG") {
    return "OAK";
  } else if (nama == "SPRUCE_LOG") {
    return "SPRUCE";
  } else if (nama == "BIRCH_LOG") {
    return "BIRCH";
  } else if (nama == "OAK_PLANK") {
    return "OAK";
  } else if (nama == "SPRUCE_PLANK") {
    return "SPRUCE";
  } else if (nama == "BIRCH_PLANK") {
    return "BIRCH";
  } else if (nama == "STICK") {
    return "N/A";
  } else if (nama == "COBBLESTONE") {
    return "COBBLE";
  } else if (nama == "BLACKSTONE") {
    return "BLACK";
  } else if (nama == "IRON_INGOT") {
    return "N/A";
  } else if (nama == "IRON_NUGGET") {
    return "N/A";
  } else if (nama == "DIAMOND") {
    return "N/A";
  } else if (nama == "WOODEN_PICKAXE") {
    return "WOODEN";
  } else if (nama == "STONE_PICKAXE") {
    return "STONE";
  } else if (nama == "IRON_PICKAXE") {
    return "IRON";
  } else if (nama == "DIAMOND_PICKAXE") {
    return "DIAMOND";
  } else if (nama == "WOODEN_AXE") {
    return "WOODEN";
  } else if (nama == "STONE_AXE") {
    return "STONE";
  } else if (nama == "IRON_AXE") {
    return "IRON";
  } else if (nama == "DIAMOND_AXE") {
    return "DIAMOND";
  } else if (nama == "WOODEN_SWORD") {
    return "WOODEN";
  } else if (nama == "STONE_SWORD") {
    return "STONE";
  } else if (nama == "IRON_SWORD") {
    return "IRON";
  } else if (nama == "DIAMOND_SWORD") {
    return "DIAMOND";
  }
  return "N/A";
}

class Item {
  public:
    string nama;
    string jenis;
    string variasi;
    int qty;
  public:
    Item() {
      this->nama = "N/A";
      this->jenis = "N/A";
      this->variasi = "N/A";
    }
    Item(string nama, string jenis) {
      this->nama = nama;
      this->jenis = jenis;
      this->variasi = "N/A";
    }
    Item(string nama, string jenis, string variasi) {
      this->nama = nama;
      this->jenis = jenis;
      this->variasi = variasi;
    }
    virtual int getQty() {
      return -1;
    }
    virtual void setQty(int newQty) {}
    virtual int getDurability() {
      return -1;
    }
    friend int getItemID(Item& i) {
      /* Sementara hardcoded, nanti pakai map aja ya */
      if (i.nama == "OAK_LOG") {
        return 1;
      } else if (i.nama == "SPRUCE_LOG") {
        return 2;
      } else if (i.nama == "BIRCH_LOG") {
        return 3;
      } else if (i.nama == "OAK_PLANK") {
        return 4;
      } else if (i.nama == "SPRUCE_PLANK") {
        return 5;
      } else if (i.nama == "BIRCH_PLANK") {
        return 6;
      } else if (i.nama == "STICK") {
        return 7;
      } else if (i.nama == "COBBLESTONE") {
        return 8;
      } else if (i.nama == "BLACKSTONE") {
        return 9;
      } else if (i.nama == "IRON_INGOT") {
        return 10;
      } else if (i.nama == "IRON_NUGGET") {
        return 11;
      } else if (i.nama == "DIAMOND") {
        return 12;
      } else if (i.nama == "WOODEN_PICKAXE") {
        return 13;
      } else if (i.nama == "STONE_PICKAXE") {
        return 14;
      } else if (i.nama == "IRON_PICKAXE") {
        return 15;
      } else if (i.nama == "DIAMOND_PICKAXE") {
        return 16;
      } else if (i.nama == "WOODEN_AXE") {
        return 17;
      } else if (i.nama == "STONE_AXE") {
        return 18;
      } else if (i.nama == "IRON_AXE") {
        return 19;
      } else if (i.nama == "DIAMOND_AXE") {
        return 20;
      } else if (i.nama == "WOODEN_SWORD") {
        return 21;
      } else if (i.nama == "STONE_SWORD") {
        return 22;
      } else if (i.nama == "IRON_SWORD") {
        return 23;
      } else if (i.nama == "DIAMOND_SWORD") {
        return 24;
      }
      return 0;
    }
};

class Nontool : public Item {
  public:
    int qty;
  public:
    Nontool(string nama, string jenis, string variasi, int qty) : Item(nama, jenis, variasi) {
      this->qty = qty;
    }
    Nontool(string nama, string jenis, int qty) : Item(nama, jenis) {
      this->qty = qty;
    }
    int getQty() {
      return qty; 
    }
    void setQty(int newQty) {
      this->qty = newQty;
    }
};

class Tool : public Item {
  public:
    int durability;
  public:
    Tool(string nama, string jenis, string variasi) : Item(nama, jenis, variasi) {
      this->durability = 10;
    }
    int getDurability() {
      return durability;
    }
};

class Inventory {
  public:
    vector<vector<Item*>> invMatrix;
  public:
    Inventory() {
      vector<Item*> tmp;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++) {
          tmp.push_back(new Item());
        }
        invMatrix.push_back(tmp);
      }
    }
    void printInventory() {
      int slot = 0;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 9; j ++) {
          if (invMatrix[i][j]->getQty() > 0) {
            /* Nontool */
            cout << "[" << setfill('0') << setw(2) << slot << "> " << invMatrix[i][j]->nama << ":" << invMatrix[i][j]->getQty() << "] ";
          }
          if (invMatrix[i][j]->getDurability() > 0) {
            /* Tool */
            cout << "[" << setfill('0') << setw(2) << slot << "> " << invMatrix[i][j]->nama << ":" << invMatrix[i][j]->getDurability() << "/10] ";
          }
          if (invMatrix[i][j]->nama == "N/A") {
            cout << "[" << setfill('0') << setw(2) << slot << "> " << "EMPTY" << "] ";
          }
          slot ++;
        }
        cout << endl;
      }
    }
    void giveItem(string itemName, int qty) {
      /* Isi ke jenis yang sama dulu */
      for (int i = 0; i < 3 && qty > 0; i ++) {
        for (int j = 0; j < 9 && qty > 0; j ++) {
          if ((*invMatrix[i][j]).nama == itemName) {
            if ((*invMatrix[i][j]).getQty() + qty <= 64) {
              (*invMatrix[i][j]).setQty((*invMatrix[i][j]).getQty() + qty);
              qty = 0;
            } else {
              int terisi = 64 - (*invMatrix[i][j]).getQty();
              (*invMatrix[i][j]).setQty(64);
              qty -= terisi;
            }
          }
        }
      }
      /* Qty masih ada, isi ke slot kosong */
      for (int i = 0; i < 3 && qty > 0; i ++) {
        for (int j = 0; j < 9 && qty > 0; j ++) {
          if ((*invMatrix[i][j]).nama == "N/A") {
            if (qty <= 64) {
              // delete invMatrix[i][j]; BIKIN ANEH
              invMatrix[i][j] = new Nontool(itemName, getJenisFromNama(itemName), getVariasiFromNama(itemName), qty);
              qty = 0;
            } else {
              // delete invMatrix[i][j]; BIKIN ANEH
              invMatrix[i][j] = new Nontool(itemName, getJenisFromNama(itemName), getVariasiFromNama(itemName), 64);
              qty -= 64;
            }
          }
        }
      }
    }
    void discardItem(int slot, int qty) {
      /* Konversi slot ke [row][col] */
      int row = 0; int col = 0;
      while (slot > 0) {
        slot --;
        col ++;
        if (col == 9) {
          col = 0;
          row ++;
        }
      }
      if (invMatrix[row][col]->getQty() > qty) {
        invMatrix[row][col]->setQty(invMatrix[row][col]->getQty() - qty);
      } else if (invMatrix[row][col]->getQty() == qty) {
        // delete invMatrix[i][j]; BIKIN ANEH
        invMatrix[row][col] = new Item();
      } else {
        /* exception */
        cout << "qty terlalu besar/item tidak ada" << endl;
      }
    }
};

class Crafting {
  public:
    vector<vector<Item*>> craftingMatrix;
    Item* craftedItem;
  public:
    Crafting() {
      vector<Item*> tmp;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          tmp.push_back(new Item());
        }
        craftingMatrix.push_back(tmp);
      }
      craftedItem = new Item();
    }

    void printCrafting() {
      int slot = 0;
      for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
          if (craftingMatrix[i][j]->getQty() > 0) {
            /* Nontool */
            cout << "[" << setfill('0') << setw(2) << slot << "> " << craftingMatrix[i][j]->nama << ":" << craftingMatrix[i][j]->getQty() << "] ";
          }
          if (craftingMatrix[i][j]->getDurability() > 0) {
            /* Tool */
            cout << "[" << setfill('0') << setw(2) << slot << "> " << craftingMatrix[i][j]->nama << ":" << craftingMatrix[i][j]->getDurability() << "/10] ";
          }
          if (craftingMatrix[i][j]->nama == "N/A") {
            cout << "[" << setfill('0') << setw(2) << slot << "> " << "EMPTY" << "] ";
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

  while (true) {
    cout << "> ";
    string input;
    cin >> input;
    if (input == "SHOW") {
      cout << "CRAFTING TABLE" << endl;
      c.printCrafting();
      cout << "INVENTORY" << endl;
      i.printInventory();
    } else if (input == "GIVE") {
      string itemName; int qty;
      cin >> itemName >> qty;
      i.giveItem(itemName, qty);
    } else if (input == "DISCARD") {
      string slot; int qty;
      cin >> slot >> qty;
      int iSlot = stoi(slot.substr(1));
      i.discardItem(iSlot, qty);
    }
  }

  return 0;
}