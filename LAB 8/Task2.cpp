#include <iostream>
using namespace std;

class BankAccount;

void moveMoney(BankAccount &source, BankAccount &target, double amt);

class BankAccount {
private:
    int accID;
    double funds;

public:
    BankAccount(int id, double initial) : accID(id), funds(initial) {}

    friend class Supervisor;
    friend void moveMoney(BankAccount &source, BankAccount &target, double amt);
};

class Supervisor {
public:
    void addMoney(BankAccount &ba, double amt) {
        if (amt > 0) {
            ba.funds += amt;
            cout << "Deposited $" << amt << " into account " << ba.accID << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void takeOut(BankAccount &ba, double amt) {
        if (amt > 0 && amt <= ba.funds) {
            ba.funds -= amt;
            cout << "Withdrew $" << amt << " from account " << ba.accID << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void show(const BankAccount &ba) {
        cout << "Account Number: " << ba.accID << ", Balance: $" << ba.funds << endl;
    }
};

void moveMoney(BankAccount &source, BankAccount &target, double amt) {
    if (amt > 0 && source.funds >= amt) {
        source.funds -= amt;
        target.funds += amt;
        cout << "Transferred $" << amt << " from Account " << source.accID
             << " to Account " << target.accID << endl;
    } else {
        cout << "Transfer failed: Insufficient balance or invalid amount." << endl;
    }
}

int main() {
    BankAccount a1(101, 1000.0);
    BankAccount a2(102, 500.0);

    Supervisor spv;

    cout << "Initial Account States:\n";
    spv.show(a1);
    spv.show(a2);

    spv.addMoney(a1, 200.0);
    spv.takeOut(a2, 100.0);
    moveMoney(a1, a2, 300.0);

    cout << "\nFinal Account States:\n";
    spv.show(a1);
    spv.show(a2);

    return 0;
}
