#include <iostream>
#include <string>
using namespace std;

class SecuritySystem {
    string securityLevel;

public:
    SecuritySystem(string level) : securityLevel(level) {
        cout << "Security System activated at level: " << securityLevel << endl;
    }

    ~SecuritySystem() {}

    string getSecurityLevel() {
        return securityLevel;
    }
};

class AutomatedHome {
    SecuritySystem system;

public:
    AutomatedHome(string level) : system(level) {}

    void showDetails() {
        cout << "Automated Home Status: " << endl;
        cout << "Security Level: " << system.getSecurityLevel() << endl;
    }

    ~AutomatedHome() {}
};

int main() {
    AutomatedHome house1("High");
    house1.showDetails();
}
