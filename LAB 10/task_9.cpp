#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream write("log.txt");
    write << "Alpha Bravo Charlie." << endl;
    write << "Delta Echo Foxtrot." << endl;
    write << "Golf Hotel India.";
    write.close();
    ifstream read("log.txt");
    char buf[11];
    read.read(buf, 10);
    cout << read.tellg() << endl;
    read.read(buf, 10);
    cout << read.tellg() << endl;
    read.close();
    return 0;
}
