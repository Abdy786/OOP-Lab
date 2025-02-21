#include <iostream>
#include <string>
using namespace std;

class RentedCar {
private:
    string manufacturer;
    string type;
    double dailyRate;
    bool isAvailable;

public:
    RentedCar(string m = "Unknown", string t = "Generic", double dr = 0.0) 
        : manufacturer(m), type(t), dailyRate(dr), isAvailable(true) {}
    
    void setDetails(string m, string t, double dr) {
        manufacturer = m;
        type = t;
        dailyRate = dr;
    }
    
    bool checkAvailability() { return isAvailable; }
    
    double discountRate(int days) {
        if (days > 10) return 0.1;
        else if (days > 5) return 0.05;
        else return 0.0;
    }
    
    void rent(int days) {
        if (!isAvailable) cout << "Car is not available." << endl;
        else {
            double discount = discountRate(days);
            double totalCost = dailyRate * days * (1 - discount);
            isAvailable = false;
            cout << "Rental cost: $" << totalCost << " (" << (discount*100) << "% discount)" << endl;
        }
    }
    
    void display() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Type: " << type << endl;
        cout << "Daily Rate: $" << dailyRate << endl;
        cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

int main() {
    RentedCar car("Tesla", "Model X", 150.0);
    car.display();
    car.rent(7);
    car.display();
    return 0;
}