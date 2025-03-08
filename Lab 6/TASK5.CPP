#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(int id, bool stat) : deviceID(id), status(stat) {}

    virtual void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
    }
};

class SmartPhone : virtual public Device {
protected:
    float screenSize;
public:
    SmartPhone(int id, bool stat, float size) : Device(id, stat), screenSize(size) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device {
protected:
    bool heartRateMonitor;
public:
    SmartWatch(int id, bool stat, bool hr) : Device(id, stat), heartRateMonitor(hr) {}

    void displayDetails() override {
        Device::displayDetails();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch {
private:
    int stepCounter;
public:
    SmartWearable(int id, bool stat, float size, bool hr, int steps)
        : Device(id, stat), SmartPhone(id, stat, size), SmartWatch(id, stat, hr), stepCounter(steps) {}

    void displayDetails() override {
        SmartPhone::displayDetails(); 
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    int id, steps;
    bool stat, hr;
    float size;

    cout << "Enter Device ID: ";
    cin >> id;
    cout << "Enter Device Status (1 for ON, 0 for OFF): ";
    cin >> stat;
    cout << "Enter Screen Size (in inches): ";
    cin >> size;
    cout << "Heart Rate Monitor Available? (1 for Yes, 0 for No): ";
    cin >> hr;
    cout << "Enter Step Counter value: ";
    cin >> steps;

    SmartWearable wearable(id, stat, size, hr, steps);

    cout << "\n--- Smart Wearable Details ---\n";
    wearable.displayDetails();

    return 0;
}
