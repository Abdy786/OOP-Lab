#include <iostream>
using namespace std;

class MenuItem {
public:
    string dishName;
    double price;

    MenuItem(string n, double p) {
        dishName = n;
        price = p;
    }

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string n, double p) : MenuItem(n, p) {}

    void showDetails() {
        cout << "Appetizer: " << dishName << ", Price: " << price << endl;
    }

    void prepare() {
        cout << "Chop veggies and mix sauce" << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string n, double p) : MenuItem(n, p) {}

    void showDetails() {
        cout << "Main Course: " << dishName << ", Price: " << price << endl;
    }

    void prepare() {
        cout << "Cook meat and add spices" << endl;
    }
};

int main() {
    Appetizer a("Spring Rolls", 199);
    MainCourse m("Chicken Biryani", 299);

    MenuItem* m1 = &a;
    MenuItem* m2 = &m;

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    return 0;
}