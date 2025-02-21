#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    string brand;
    string model;
    bool available;

public:
    Auto(string b = "Unknown", string m = "Generic") : brand(b), model(m), available(true) {}
    
    Auto(const Auto& other) : brand(other.brand), model(other.model), available(other.available) {}
    
    ~Auto() { cout << "Auto object deleted." << endl; }
    
    void setDetails(string b, string m) {
        brand = b;
        model = m;
    }
    
    bool checkAvailability() { return available; }
    
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }
};

int main() {
    Auto original("Toyota", "RAV4");
    Auto copy = original;
    original.setDetails("Toyota", "Tacoma");
    original.display();
    copy.display();
    return 0;
}