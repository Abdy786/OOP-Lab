#include <iostream>
#include <exception>
using namespace std;

class TemperatureOutOfRange : public exception {};

template <typename Unit>
Unit celsiusToFahrenheit(Unit tempCelsius) {
    const double ABSOLUTE_ZERO = -273.15;
    if (tempCelsius < ABSOLUTE_ZERO) {
        throw TemperatureOutOfRange();
    }
    return static_cast<Unit>((tempCelsius * 9.0 / 5.0) + 32);
}

int main() {
    try {
        cout << "Attempting to convert -300C..." << endl;
        celsiusToFahrenheit(-300.0);
    } catch (const TemperatureOutOfRange& e) {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }
    return 0;
}