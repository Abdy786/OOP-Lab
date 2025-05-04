#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Vehicle {
public:
    string type;
    int year;
};

class EV : public Vehicle {
public:
    int battery;
};

class AutoCar : public Vehicle {
public:
    double version;
};

int main() {
    ifstream file("vehicles.txt");
    string entry;
    while (getline(file, entry)) {
        if (entry.empty() || entry[0] == '#') continue;
        string fields[5], temp = "";
        int k = 0;
        for (char c : entry) {
            if (c == ',') {
                fields[k++] = temp;
                temp = "";
            } else {
                temp += c;
            }
        }
        fields[k] = temp;
        if (fields[0] == "ElectricVehicle") {
            EV e;
            e.battery = stoi(fields[4].substr(fields[4].find(':') + 1));
            cout << e.battery << endl;
        } else if (fields[0] == "AutonomousCar") {
            AutoCar a;
            a.version = stod(fields[4].substr(fields[4].find(':') + 1));
            cout << a.version << endl;
        }
    }
    file.close();
    return 0;
}
