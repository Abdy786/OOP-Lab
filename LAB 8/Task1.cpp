#include <iostream>
using namespace std;

class ComplexNumber {
protected:
    double x, y;

public:
    ComplexNumber(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

    ComplexNumber add(const ComplexNumber& z) {
        return ComplexNumber(x + z.x, y + z.y);
    }

    ComplexNumber subtract(const ComplexNumber& z) {
        return ComplexNumber(x - z.x, y - z.y);
    }

    ComplexNumber multiply(const ComplexNumber& z) {
        double realPart = x * z.x - y * z.y;
        double imagPart = x * z.y + y * z.x;
        return ComplexNumber(realPart, imagPart);
    }

    ComplexNumber divide(const ComplexNumber& z) {
        double denom = z.x * z.x + z.y * z.y;
        if (denom == 0)
            throw "Cannot divide by zero!";
        double re = (x * z.x + y * z.y) / denom;
        double im = (y * z.x - x * z.y) / denom;
        return ComplexNumber(re, im);
    }

    friend ostream& operator<<(ostream& display, const ComplexNumber& z) {
        display << "(" << z.x;
        if (z.y >= 0)
            display << "+" << z.y << "i)";
        else
            display << "-" << -z.y << "i)";
        return display;
    }

    friend double getMagnitude(const ComplexNumber& z);

private:
    static double manualSqrt(double num) {
        if (num == 0) return 0;
        double g = num / 2;
        for (int k = 0; k < 10; ++k) {
            g = (g + num / g) / 2;
        }
        return g;
    }
};

double getMagnitude(const ComplexNumber& z) {
    double total = z.x * z.x + z.y * z.y;
    return ComplexNumber::manualSqrt(total);
}

int main() {
    ComplexNumber a(2, 3), b(1, -5);

    cout << "Complex Number 1: " << a << endl;
    cout << "Complex Number 2: " << b << endl;

    ComplexNumber s = a.add(b);
    cout << "Sum: " << s << endl;

    ComplexNumber d = a.subtract(b);
    cout << "Difference: " << d << endl;

    ComplexNumber m = a.multiply(b);
    cout << "Product: " << m << endl;

    ComplexNumber q = a.divide(b);
    cout << "Quotient: " << q << endl;

    cout << "Magnitude of Complex Number 1: " << getMagnitude(a) << endl;
    cout << "Magnitude of Complex Number 2: " << getMagnitude(b) << endl;

    return 0;
}
