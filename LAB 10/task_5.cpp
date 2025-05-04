#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Truck {
public:
    int year;
    int cargo;
    int battery;
};

int main() {
    ifstream file("vehicles.txt");
    string text;
    while (getline(file, text)) {
        if (text.empty() || text[0] == '#') continue;
        string parts[5], val = "";
        int pos = 0;
        for (char c : text) {
            if (c == ',') {
                parts[pos++] = val;
                val = "";
            } else {
                val += c;
            }
        }
        parts[pos] = val;
        if (parts[0] == "HybridTruck") {
            Truck t;
            int p1 = parts[4].find(':');
            int p2 = parts[4].find('|');
            int p3 = parts[4].rfind(':');
            t.cargo = stoi(parts[4].substr(p1+1, p2 - p1 - 1));
            t.battery = stoi(parts[4].substr(p3+1));
            cout << t.cargo << " " << t.battery << endl;
        }
    }
    file.close();
    return 0;
}
