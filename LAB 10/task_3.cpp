#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream input("vehicles.txt");
    if (input.is_open()) {
        while (getline(input, line)) {
            if (line.length() == 0 || line[0] == '#') continue;
            int commas = 0;
            string year = "";
            for (char c : line) {
                if (c == ',') {
                    commas++;
                    continue;
                }
                if (commas == 3) year += c;
            }
            cout << stoi(year) << endl;
        }
        input.close();
    }
    return 0;
}
