#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string data;
    ifstream inputFile("vehicles.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, data)) {
            if (!data.empty() && data[0] != '#') {
                cout << data << endl;
            }
        }
        inputFile.close();
    } else {
        cout << "File not found" << endl;
    }
    return 0;
}
