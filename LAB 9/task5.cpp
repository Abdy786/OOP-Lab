
#include <iostream>
using namespace std;

class Shipment {
public:
    string trackingNumber;
    double weight;

    Shipment(string t, double w) {
        trackingNumber = t;
        weight = w;
    }

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
public:
    AirFreight(string t, double w) : Shipment(t, w) {}

    void estimateDeliveryTime() {
        cout << "Air Delivery Time: 2 days" << endl;
    }

    void showDetails() {
        cout << "Air Shipment - Tracking: " << trackingNumber << ", Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string t, double w) : Shipment(t, w) {}

    void estimateDeliveryTime() {
        cout << "Ground Delivery Time: 5 days" << endl;
    }

    void showDetails() {
        cout << "Ground Shipment - Tracking: " << trackingNumber << ", Weight: " << weight << " kg" << endl;
    }
};

int main() {
    Shipment* s1 = new AirFreight("AF123", 12.5);
    Shipment* s2 = new GroundShipment("GS456", 20.0);

    s1->showDetails();
    s1->estimateDeliveryTime();

    s2->showDetails();
    s2->estimateDeliveryTime();

    delete s1;
    delete s2;

    return 0;
}
