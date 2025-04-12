#include <iostream>
using namespace std;

class Point2D {
private:
    double xCoord, yCoord;

public:
    Point2D(double a = 0, double b = 0) : xCoord(a), yCoord(b) {}

    Point2D operator+(const Point2D& p) const {
        return Point2D(xCoord + p.xCoord, yCoord + p.yCoord);
    }

    Point2D operator-(const Point2D& p) const {
        return Point2D(xCoord - p.xCoord, yCoord - p.yCoord);
    }

    Point2D operator*(double val) const {
        return Point2D(xCoord * val, yCoord * val);
    }

    friend double getDot(const Point2D& a, const Point2D& b);
    friend ostream& operator<<(ostream& out, const Point2D& pt);
};

double getDot(const Point2D& a, const Point2D& b) {
    return a.xCoord * b.xCoord + a.yCoord * b.yCoord;
}

ostream& operator<<(ostream& out, const Point2D& pt) {
    out << "(" << pt.xCoord << ", " << pt.yCoord << ")";
    return out;
}

int main() {
    Point2D p1(2, 1), p2(3, 2);
    Point2D added = p1 + p2;
    Point2D subtracted = p1 - p2;
    Point2D multiplied = p1 * 2;
    double result = getDot(p1, p2);

    cout << "v1: " << p1 << endl;
    cout << "v2: " << p2 << endl;
    cout << "Sum: " << added << endl;
    cout << "Difference: " << subtracted << endl;
    cout << "Scaled v1: " << multiplied << endl;
    cout << "Dot Product: " << result << endl;

    return 0;
}
