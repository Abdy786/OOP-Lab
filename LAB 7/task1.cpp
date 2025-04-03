#include <iostream>
using namespace std;

class Gadget {
protected:
    int gadgetID;
    string gadgetName;
    bool powerStatus;
    string placement;
public:
    Gadget(int id, string name, string place = " ") : gadgetID(id), gadgetName(name), placement(place) {}

    virtual void activate() {
        powerStatus = true;
        cout << gadgetName << " is now activated." << endl;
    }

    virtual void deactivate() {
        powerStatus = false;
        cout << gadgetName << " is now deactivated." << endl;
    }

    virtual void showDetails() {
        cout << "Gadget ID: " << gadgetID << endl;
        cout << "Gadget Name: " << gadgetName << endl;
        cout << "Status: " << powerStatus << endl;
        cout << "Placement: " << placement << endl;
    }
};

class Illuminator : public Gadget {
protected:
    int luminosity;
    string hueMode;
public:
    Illuminator(int id, string name, string place, int lum, string hue) : Gadget(id, name, place), luminosity(lum), hueMode(hue) {}

    void showDetails() override {
        Gadget::showDetails();
        cout << "Luminosity: " << luminosity << endl;
        cout << "Hue Mode: " << hueMode << endl;
    }
};

class ClimateController : public Gadget {
protected:
    int temperature;
public:
    ClimateController(int id, string name, string place, int temp) : Gadget(id, name, place), temperature(temp) {}

    virtual void showDetails() override {
        Gadget::showDetails();
        cout << "Current Temperature: " << temperature << "°C" << endl;
    }
};

class SurveillanceUnit : public Gadget {
protected:
    string videoResolution;
    bool recordingActive;
    bool nightVision;
public:
    SurveillanceUnit(int id, string name, string place, string res, bool nv) : Gadget(id, name, place), videoResolution(res), nightVision(nv), recordingActive(false) {}
    void activate() {
        powerStatus = true;
        recordingActive = true;
        cout << gadgetName << " is now activated and recording." << endl;
    }
    void deactivate() {
        powerStatus = false;
        recordingActive = false;
        cout << gadgetName << " is now deactivated and not recording." << endl;
    }

    void showDetails() override {
        Gadget::showDetails();
        cout << "Video Resolution: " << videoResolution << endl;
        cout << "Night Vision: " << (nightVision ? "ON" : "OFF") << endl;
        cout << "Recording Status: " << (recordingActive ? "ON" : "OFF") << endl;
    }
};

class EnergySocket : public Gadget {
private:
    int powerUsage;
    int timerSetting;
public:
    EnergySocket(int id, string name, string place, int power, int timer) : Gadget(id, name, place), powerUsage(power), timerSetting(timer) {}
    void deactivate() override {
        powerStatus = false;
        cout << gadgetName << " is now deactivated." << endl;
        cout << "Power used: " << powerUsage << " Watts" << endl;
    }

    void showDetails() override {
        Gadget::showDetails();
        cout << "Power Usage: " << powerUsage << " Watts" << endl;
        cout << "Timer Setting: " << timerSetting << " minutes" << endl;
    }
};

int main() {
    Illuminator light1(1, "Tube Light", "Drawing Room", 20, "Yellow");
    ClimateController heater1(2, "Heater", "Living Room", 25);
    SurveillanceUnit camera1(3, "Security Camera", "Backyard", "1080p", true);
    EnergySocket plug1(4, "Smart Plug", "Kitchen", 10, 5);

    light1.showDetails();
    heater1.showDetails();
    camera1.showDetails();
    plug1.deactivate();
    camera1.activate();
}