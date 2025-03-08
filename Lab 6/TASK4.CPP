#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accID;
    float accBalance;
public:
    BankAccount(int id, float bal) : accID(id), accBalance(bal) {}
    virtual void showInfo() {
        cout << "Account ID: " << accID << endl;
        cout << "Current Balance: $" << accBalance << endl;
    }
    virtual ~BankAccount() {}
};

class InterestAccount : public BankAccount {
private:
    float rate;
public:
    InterestAccount(int id, float bal, float r) : BankAccount(id, bal), rate(r) {}
    void showInfo() override {
        BankAccount::showInfo();
        cout << "Interest Rate: " << rate << "%" << endl;
    }
};

class CreditAccount : public BankAccount {
private:
    float creditLimit;
public:
    CreditAccount(int id, float bal, float limit) : BankAccount(id, bal), creditLimit(limit) {}
    void showInfo() override {
        BankAccount::showInfo();
        cout << "Credit Limit: $" << creditLimit << endl;
    }
};

int main() {
    int accID;
    float balance, rate, limit;

    cout << "Enter Interest Account details:\n";
    cout << "Account ID: ";
    cin >> accID;
    cout << "Balance: ";
    cin >> balance;
    cout << "Interest Rate (%): ";
    cin >> rate;
    InterestAccount interestAcc(accID, balance, rate);

    cout << "\nEnter Credit Account details:\n";
    cout << "Account ID: ";
    cin >> accID;
    cout << "Balance: ";
    cin >> balance;
    cout << "Credit Limit: ";
    cin >> limit;
    CreditAccount creditAcc(accID, balance, limit);

    cout << "\nInterest Account Information:\n";
    interestAcc.showInfo();

    cout << "\nCredit Account Information:\n";
    creditAcc.showInfo();
}
