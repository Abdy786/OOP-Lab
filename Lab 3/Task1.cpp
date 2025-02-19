#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    string owner;
    double balance;
    double initialBalance;
    string transactionLog[500];
    int transactionCount;

public:
    Wallet(string ownerName, double startingBalance) {
        owner = ownerName;
        balance = startingBalance;
        initialBalance = startingBalance;
        transactionCount = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionLog[transactionCount] = "Deposited: " + to_string(amount);
            transactionCount++;
            cout << "Amount Successfully Deposited." << endl;
        } else {
            cout << "Invalid amount! Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount < 0) {
            cout << "Error: Please enter a positive amount." << endl;
        } else {
            balance -= amount;
            transactionLog[transactionCount] = "Withdrawn: " + to_string(amount);
            transactionCount++;
            cout << "Withdrawal Successful. Remaining Balance: " << balance << endl;
        }
    }

    void showTransactionHistory() {
        cout << "\nTransaction History:" << endl;
        if (transactionCount == 0) {
            cout << "No transactions recorded yet." << endl;
        } else {
            for (int i = 0; i < transactionCount; i++) {
                cout << transactionLog[i] << endl;
            }
        }
    }

    void checkLowBalance() {
        if (balance <= initialBalance / 2) {
            cout << "Warning: Low Balance!" << endl;
        } else {
            cout << "Your balance is sufficient." << endl;
        }
    }

    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Wallet myWallet("Saad", 50000);
    myWallet.deposit(10000);
    myWallet.displayBalance();
    myWallet.withdraw(20000);
    myWallet.withdraw(10000);
    myWallet.displayBalance();
    myWallet.checkLowBalance();
    myWallet.showTransactionHistory();

    return 0;
}
