#include <iostream>
#include <string>
using namespace std;

class LeasedCar {
private:
    string brand;
    string model;
    double dailyPrice;
    bool available;
    double totalIncome;

public:
    LeasedCar(string b = "Unknown", string m = "Generic", double dp = 0.0) 
        : brand(b), model(m), dailyPrice(dp), available(true), totalIncome(0.0) {}
    
    void generateIncome(int days) {
        if (!available) {
            cout << "Car is unavailable." << endl;
            return;
        }
        double income = dailyPrice * days;
        totalIncome += income;
        available = false;
        cout << "Rental income: $" << income << endl;
    }
    
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Daily Price: $" << dailyPrice << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Total Income: $" << totalIncome << endl;
    }
};

int main() {
    LeasedCar car("Mercedes", "C-Class", 120.0);
    car.generateIncome(3);
    car.display();
    car.generateIncome(5);
    return 0;
}