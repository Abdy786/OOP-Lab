#include <iostream>
#include <string>
using namespace std;

class FleetCar {
private:
    string registration;
    string brand;
    bool rented;

public:
    FleetCar(string reg, string b) : registration(reg), brand(b), rented(false) {}
    
    void setRented(bool status) { rented = status; }
    
    void displayFullInfo() {
        cout << "Registration: " << registration << endl;
        cout << "Brand: " << brand << endl;
        cout << "Rental Status: " << (rented ? "Rented" : "Available") << endl;
    }
};

int main() {
    FleetCar car("XYZ-123", "Audi");
    car.displayFullInfo();
    car.setRented(true);
    car.displayFullInfo();
    return 0;
}