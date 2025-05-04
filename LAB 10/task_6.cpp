#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item {
public:
    int id;
    char name[25];
};

int main() {
    Item i;
    i.id = 101;
    strcpy(i.name, "Gadget");
    ofstream outFile("inventory.dat", ios::binary);
    outFile.write((char*)&i, sizeof(i));
    outFile.close();
    Item j;
    ifstream inFile("inventory.dat", ios::binary);
    inFile.read((char*)&j, sizeof(j));
    inFile.close();
    cout << j.id << " " << j.name;
    return 0;
}
