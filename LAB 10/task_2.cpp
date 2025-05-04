#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.size() > 0 && line.at(0) != '#') {
                for (char ch : line) {
                    if (ch == ',') {
                        cout << endl;
                    } else {
                        cout << ch;
                    }
                }
                cout << endl << endl;
            }
        }
        file.close();
    }
    return 0;
}
