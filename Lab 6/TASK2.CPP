#include<iostream>
#include <string>
using namespace std;

class Transport {
public:
    string model;
    int velocity;
    Transport(string m, int v) : model(m), velocity(v) {}
    void showInfo() {
        cout << "Model: " << model << "\nVelocity: " << velocity << " km/h\n";
    }
};

class Automobile : public Transport {
public:
    int capacity;
    Automobile(string m, int v, int cap) : Transport(m, v), capacity(cap) {}
    void showInfo() {
        cout << "Model: " << model << "\nVelocity: " << velocity << " km/h\nCapacity: " << capacity << " seats\n";
    }
};

class HybridCar : public Automobile {
public:
    int energyBackup;
    HybridCar(string m, int v, int cap, int backup) : Automobile(m, v, cap), energyBackup(backup) {}
    void showInfo() {
        cout << "Model: " << model << "\nVelocity: " << velocity << " km/h\nCapacity: " << capacity << " seats\nEnergy Backup: " << energyBackup << " hours\n";
    }
};

int main() {
    HybridCar h("Honda Vezel RS", 180, 5, 2);
    h.showInfo();
}
