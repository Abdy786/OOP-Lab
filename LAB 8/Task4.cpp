#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string name;
    double cost;

public:
    Vehicle(const string& n, double c) : name(n), cost(c) {}

    friend class Showroom;
    friend void checkCost(const Vehicle& v1, const Vehicle& v2);
};

class Showroom {
public:
    static void modifyCost(Vehicle& v, double updatedCost) {
        v.cost = updatedCost;
        cout << "\nCost has been successfully modified!\n" << endl;
    }

    static void showInfo(const Vehicle& v) {
        cout << "Vehicle: " << v.name << ", Cost: $" << v.cost << "\n" << endl;
    }
};

void checkCost(const Vehicle& v1, const Vehicle& v2) {
    if (v1.cost > v2.cost) {
        cout << v1.name << " costs more than " << v2.name << endl;
    } else if (v1.cost < v2.cost) {
        cout << v1.name << " costs less than " << v2.name << endl;
    } else {
        cout << "Both vehicles have identical costs" << endl;
    }
}

int main() {
    Vehicle v1("Porshe", 45000.0);
    Vehicle v2("Lexus", 47000.0);

    Showroom::showInfo(v1);
    Showroom::showInfo(v2);

    checkCost(v1, v2);

    Showroom::modifyCost(v1, 50000.0);
    Showroom::showInfo(v1);
    checkCost(v1, v2);

    return 0;
}
