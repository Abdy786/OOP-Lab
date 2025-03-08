#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    int ID;
    string address;
    string* name;  

public:
    Apartment(int id, string add, string& owner) : ID(id), address(add) {
        name = new string(owner);
    }

    Apartment(const Apartment& copy) : ID(copy.ID), address(copy.address) {
        name = new string(*copy.name);
    }

    ~Apartment() {
        delete name;
    }

    void display() {
        cout << "Apartment ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << *name << endl;
        cout << "\n";
    }
};

int main() {
    string name = "Abdullah";
    Apartment aprt1(1, "Saddar", name);
    Apartment aprt2(2, "Liyari", name);

    Apartment copyaprt1 = aprt1;
    Apartment copyaprt2 = aprt2;

    aprt1.display();
    aprt2.display();
    copyaprt1.display();
    copyaprt2.display();
}
