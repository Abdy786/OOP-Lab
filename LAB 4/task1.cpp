#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    double price;
    bool available;

public:
    Vehicle() : brand("Unspecified"), model("Generic"), price(0.0), available(true) {}
    
    void editDetails(string b, string m, double p) {
        brand = b;
        model = m;
        price = p;
    }
    
    bool checkStatus() { return available; }
    
    void rent(int days) {
        if (!available) cout << "Vehicle is currently rented." << endl;
        else {
            available = false;
            cout << "Rental confirmed for " << days << " days." << endl;
        }
    }
    
    void details() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Daily Rate: $" << price << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};

int main() {
    Vehicle car;
    car.editDetails("Ford", "Focus", 75.0);
    car.details();
    car.rent(5);
    car.details();
    return 0;
}