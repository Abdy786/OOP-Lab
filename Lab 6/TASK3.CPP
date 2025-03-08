#include <iostream>
#include <string>
using namespace std;

class Individual {
protected:
    string fullName;
    int years;

public:
    Individual(string fName, int y) : fullName(fName), years(y) {}

    virtual void showInfo() {
        cout << "Full Name: " << fullName << endl;
        cout << "Age: " << years << " years" << endl;
    }
};

class Educator : virtual public Individual {
protected:
    string expertise;

public:
    Educator(string fName, int y, string exp) : Individual(fName, y), expertise(exp) {}

    virtual void showInfo() {
        Individual::showInfo();
        cout << "Teaching Subject: " << expertise << endl;
    }
};

class Scientist : virtual public Individual {
protected:
    string field;

public:
    Scientist(string fName, int y, string fld) : Individual(fName, y), field(fld) {}

    virtual void showInfo() {
        Individual::showInfo();
        cout << "Field of Research: " << field << endl;
    }
};

class Scholar : public Educator, public Scientist {
private:
    int papersPublished;

public:
    Scholar(string fName, int y, string exp, string fld, int papers)
        : Individual(fName, y), Educator(fName, y, exp), Scientist(fName, y, fld), papersPublished(papers) {}

    void showInfo() {
        Educator::showInfo();
        Scientist::showInfo();
        cout << "Number of Research Papers: " << papersPublished << endl;
    }
};

int main() {
    Scholar academic("Dr. Bilal", 42, "Psychology", "Mental Health", 69);
    cout << "Scholar Profile:\n";
    academic.showInfo();
}
