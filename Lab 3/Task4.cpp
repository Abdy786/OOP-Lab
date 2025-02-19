#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
    string make;
    string model;
    float tankSize;     
    float fuelLevel;    

public:
    Vehicle(string brand, string type, float capacity) {
        make = brand;
        model = type;
        tankSize = capacity;
        fuelLevel = capacity;  
    }

    void drive(float distance) {
        float fuelUsed = distance * 0.1;  
        if (fuelUsed > fuelLevel) {
            cout << "⛔ Not enough fuel to drive " << distance << " km!\n";
        } else {
            fuelLevel -= fuelUsed;
            cout << "🚗 Drove " << distance << " km. Fuel used: " << fuelUsed << " liters.\n";
            checkFuel();
        }
    }

    void refuel(float amount) {
        if (amount <= 0) {
            cout << "⚠️ Invalid fuel amount!\n";
            return;
        }

        if (fuelLevel + amount > tankSize) {
            cout << "⛽ Tank overflow! Filling up to full capacity.\n";
            fuelLevel = tankSize;
        } else {
            fuelLevel += amount;
            cout << "✅ Added " << amount << " liters of fuel.\n";
        }
        checkFuel();
    }

    void checkFuel() {
        cout << "⛽ Current fuel level: " << fuelLevel << " liters.\n";
        if (fuelLevel < 5) {
            cout << "⚠️ Warning: Low fuel! Please refill soon.\n";
        }
    }

    void displayInfo() {
        cout << "\n🚘 Vehicle Info:\n";
        cout << "Make & Model: " << make << " " << model << "\n";
        cout << "Tank Capacity: " << tankSize << " liters\n";
        cout << "Fuel Level: " << fuelLevel << " liters\n\n";
    }
};

int main() {
    Vehicle myCar("Honda", "City", 55);  

    myCar.displayInfo();
    
    myCar.drive(110);  
    myCar.drive(190);  
    
    myCar.refuel(20);
    myCar.refuel(40);  
    
    myCar.displayInfo();  
    return 0;
}
