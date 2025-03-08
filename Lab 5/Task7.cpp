#include <iostream>
#include <string>
using namespace std;

class Item {
    int itemID;
    string itemName;
    int stock;

public:
    Item(int id, string name, int qty) : itemID(id), itemName(name), stock(qty) {}

    int getItemID() {
        return itemID;
    }

    string getItemName() {
        return itemName;
    }

    int getStock() {
        return stock;
    }

    void displayItem() {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Stock Available: " << stock << endl;
    }
};

class Storage {
    Item** inventory;
    int itemCount;
    int capacity;

public:
    Storage(int cap) : capacity(cap), itemCount(0) {
        inventory = new Item*[capacity];
    }

    void addItem(int id, string name, int qty) {
        if (itemCount < capacity) {
            inventory[itemCount] = new Item(id, name, qty);
            itemCount++;
        } else {
            cout << "Storage is full. Cannot add more items." << endl;
        }
    }

    void findItemByID(int id) {
        bool exists = false;
        for (int i = 0; i < itemCount; i++) {
            if (inventory[i]->getItemID() == id) {
                inventory[i]->displayItem();
                exists = true;
                break;
            }
        }
        if (!exists) {
            cout << "No item found with ID " << id << endl;
        }
    }

    void showAllItems() {
        for (int i = 0; i < itemCount; i++) {
            inventory[i]->displayItem();
            cout << endl;
        }
    }

    void arrangeItems() {
        for (int i = 0; i < itemCount - 1; i++) {
            for (int j = 0; j < itemCount - i - 1; j++) {
                if (inventory[j]->getItemName() > inventory[j + 1]->getItemName()) {
                    Item* temp = inventory[j];
                    inventory[j] = inventory[j + 1];
                    inventory[j + 1] = temp;
                }
            }
        }
        showAllItems();
    }

    ~Storage() {
        for (int i = 0; i < itemCount; i++) {
            delete inventory[i];
        }
        delete[] inventory;
    }
};

int main() {
    Storage store(5);

    store.addItem(002, "Desk", 5);
    store.addItem(001, "Chair", 10);
    store.addItem(004, "Phone", 3);
    store.addItem(005, "TV", 10);
    store.addItem(003, "Microwave", 9);

    store.arrangeItems();

    store.findItemByID(001);
    store.findItemByID(002);
}
