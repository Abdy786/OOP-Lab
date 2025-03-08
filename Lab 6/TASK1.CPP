#include <iostream>
#include <string>

using namespace std;

class Worker {
protected:
    string workerName;
    float baseSalary;
public:
    Worker(string n, float s) : workerName(n), baseSalary(s) {}

    virtual void showInfo() {
        cout << "Worker Name: " << workerName << endl;
        cout << "Base Salary: $" << baseSalary << endl;
    }
};

class Supervisor : public Worker {
private:
    float extraAllowance;
public:
    Supervisor(string n, float s, float a) : Worker(n, s), extraAllowance(a) {}

    void showInfo() override {
        Worker::showInfo();
        cout << "Extra Allowance: $" << extraAllowance << endl;
    }
};

int main() {
    string workerName;
    float baseSalary, extraAllowance;

    cout << "Enter Supervisor's Name: ";
    cin >> workerName;
    cout << "Enter Base Salary: ";
    cin >> baseSalary;
    cout << "Enter Extra Allowance: ";
    cin >> extraAllowance;

    Supervisor sup(workerName, baseSalary, extraAllowance);
    cout << "\nSupervisor Details:\n";
    sup.showInfo();
}
