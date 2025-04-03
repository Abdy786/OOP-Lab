#include <iostream>
using namespace std;

class Item {
protected:
    int itemID;
    string itemName;
    double cost;
    int inventoryCount;

public:
    Item(int id, string name, double c, int inv) 
        : itemID(id), itemName(name), cost(c), inventoryCount(inv) {}

    virtual void applyDiscount(double discountRate) {
        cost -= cost * (discountRate / 100);
    }

    virtual double calculateTotalCost(int quantity) {
        return cost * quantity;
    }

    virtual void displayItemInfo() const {
        cout << "ID : " << itemID << endl;
        cout << "Name : " << itemName << endl;
        cout << "Cost : " << cost << endl;
        cout << "Inventory Count : " << inventoryCount << endl;
    }

    double getCost() const { return cost; }
    
    friend double operator+(const Item &i1, const Item &i2) {
        return i1.cost + i2.cost;
    }

    friend ostream &operator<<(ostream &os, const Item &i) {
        i.displayItemInfo();
        return os;
    }
};

class ElectronicDevice : public Item {
protected:
    int guaranteePeriod;
    string manufacturer;

public:
    ElectronicDevice(int id, string name, double c, int inv, int gp, string man) 
        : Item(id, name, c, inv), guaranteePeriod(gp), manufacturer(man) {}

    void displayItemInfo() const override {
        Item::displayItemInfo();
        cout << "Guarantee Period: " << guaranteePeriod << " years" << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Apparel : public Item {
protected:
    string fit;
    string hue;
    string textile;

public:
    Apparel(int id, string name, double c, int inv, string f, string h, string t) 
        : Item(id, name, c, inv), fit(f), hue(h), textile(t) {}

    void applyDiscount(double discountRate) override {
        cost -= cost * (discountRate / 100);
        cout << "Seasonal Discount Offer Applied" << endl;
    }

    void displayItemInfo() const override {
        Item::displayItemInfo();
        cout << "Fit: " << fit << endl;
        cout << "Hue: " << hue << endl;
        cout << "Textile: " << textile << endl;
    }
};

class Edible : public Item {
protected:
    string expiryDate;
    double energyContent;

public:
    Edible(int id, string name, double c, int inv, string expDate, double energy) 
        : Item(id, name, c, inv), expiryDate(expDate), energyContent(energy) {}

    void displayItemInfo() const override {
        Item::displayItemInfo();
        cout << "Expiry Date: " << expiryDate << endl;
        cout << "Energy Content: " << energyContent << " kcal" << endl;
    }

    double calculateTotalCost(int quantity) override {
        return (quantity > 10) ? cost * quantity * 0.9 : cost * quantity;
    }
};

int main() {
    ElectronicDevice d1(1, "Smartphone", 15000, 10, 2, "Apple");
    Apparel a1(2, "Jeans", 3000, 50, "M", "Blue", "Denim");
    Edible e1(3, "Chocolate", 200, 100, "2025-12-31", 250);

    a1.applyDiscount(15);
    cout << "Total cost for 6 chocolates: $" << e1.calculateTotalCost(6) << "\n";

    cout << "\nItem Details:\n";
    cout << d1 << "\n";
    cout << a1 << "\n";
    cout << e1 << "\n";
    
    return 0;
}