#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;
const int MAX_TRANSACTIONS = 200;

class Account {
private:
    int id;
    string name, type;
    double balance;

public:
    Account() : id(-1), balance(0) {}

    void create(int accID, const string& holder, const string& accType, double initial) {
        id = accID;
        name = holder;
        type = accType;
        balance = initial;
    }

    void show() const {
        if (id == -1) { cout << "No such account.\n"; return; }
        cout << "\n--- Account Info ---\n";
        cout << "ID: " << id << "\nHolder: " << name
             << "\nType: " << type << "\nBalance: $" << balance << endl;
    }

    bool deposit(double amt) {
        if (amt <= 0) return false;
        balance += amt;
        return true;
    }

    bool withdraw(double amt) {
        if (amt <= 0 || amt > balance) return false;
        balance -= amt;
        return true;
    }

    int getID() const { return id; }
    double getBalance() const { return balance; }

    void remove() { id = -1; name.clear(); type.clear(); balance = 0; }
};

class Transaction {
public:
    int fromID, toID;
    string type;
    double amount;

    void log(int from, int to, double amt, const string& t) {
        fromID = from;
        toID = to;
        amount = amt;
        type = t;
    }

    void print() const {
        cout << type << " | From: " << fromID 
             << " | To: " << toID 
             << " | Amount: $" << amount << endl;
    }
};

class User {
protected:
    string username, password;
public:
    User() {}
    User(string u, string p) : username(u), password(p) {}
    bool login(string u, string p) { return u == username && p == password; }
    virtual void menu() = 0;
};

Account accounts[MAX_ACCOUNTS];
Transaction logs[MAX_TRANSACTIONS];

int accCount = 0, logCount = 0;

int findAcc(int id) {
    for (int i = 0; i < accCount; i++)
        if (accounts[i].getID() == id) return i;
    return -1;
}

void saveLog(int from, int to, double amt, string type) {
    if (logCount < MAX_TRANSACTIONS)
        logs[logCount++].log(from, to, amt, type);
}

class Admin : public User {
public:
    Admin(string u="admin", string p="1234") : User(u,p) {}

    void createAccount() {
        int id; string name, type; double bal;

        cout << "Enter new Account ID: ";
        cin >> id;
        if (findAcc(id) != -1) { cout << "ID already exists.\n"; return; }

        cin.ignore();
        cout << "Holder Name: "; getline(cin, name);
        cout << "Account Type: "; getline(cin, type);
        cout << "Initial Balance: "; cin >> bal;

        accounts[accCount++].create(id, name, type, bal);
        cout << "Account Created!\n";
    }

    void viewAccount() {
        int id; cout << "Enter Account ID: "; cin >> id;
        int idx = findAcc(id);
        if (idx != -1) accounts[idx].show();
        else cout << "Not found.\n";
    }

    void deleteAccount() {
        int id; cout << "Enter Account ID: "; cin >> id;
        int idx = findAcc(id);
        if (idx != -1) {
            accounts[idx].remove();
            cout << "Deleted.\n";
        } else cout << "Not found.\n";
    }

    void showLogs() {
        cout << "\n--- Transaction Log ---\n";
        for (int i = 0; i < logCount; i++) logs[i].print();
    }

    void menu() override {
        int ch;
        do {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. Create Account\n2. View Account\n3. Delete Account\n4. View Logs\n0. Logout\nChoice: ";
            cin >> ch;

            switch (ch) {
                case 1: createAccount(); break;
                case 2: viewAccount(); break;
                case 3: deleteAccount(); break;
                case 4: showLogs(); break;
                case 0: break;
                default: cout << "Invalid.\n";
            }
        } while (ch != 0);
    }
};

class Customer : public User {
    int myID;
public:
    Customer(string u, string p, int accID) : User(u,p), myID(accID) {}

    void myAccount() {
        int idx = findAcc(myID);
        if (idx != -1) accounts[idx].show();
        else cout << "Not found.\n";
    }

    void deposit() {
        int idx = findAcc(myID);
        double amt;
        cout << "Amount: ";
        cin >> amt;

        if (accounts[idx].deposit(amt)) {
            saveLog(myID, myID, amt, "Deposit");
            cout << "Deposited.\n";
        } else cout << "Invalid.\n";
    }

    void withdraw() {
        int idx = findAcc(myID);
        double amt;
        cout << "Amount: ";
        cin >> amt;

        if (accounts[idx].withdraw(amt)) {
            saveLog(myID, myID, amt, "Withdraw");
            cout << "Withdrawn.\n";
        } else cout << "Invalid.\n";
    }

    void menu() override {
        int ch;
        do {
            cout << "\n--- Customer Menu ---\n";
            cout << "1. View Account\n2. Deposit\n3. Withdraw\n0. Logout\nChoice: ";
            cin >> ch;

            switch (ch) {
                case 1: myAccount(); break;
                case 2: deposit(); break;
                case 3: withdraw(); break;
                case 0: break;
                default: cout << "Invalid.\n";
            }
        } while (ch != 0);
    }
};

Admin admin1;
Customer customer1("user", "pass", 101);

int main() {
    int ch;

    accounts[accCount++].create(101, "Test User", "Savings", 500);

    do {
        cout << "\n=== BANK SYSTEM ===\n1. Login\n0. Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            string u,p;
            cout << "Username: ";  cin >> u;
            cout << "Password: ";  cin >> p;

            if (admin1.login(u,p)) { cout << "\nAdmin logged in.\n"; admin1.menu(); }
            else if (customer1.login(u,p)) { cout << "\nCustomer logged in.\n"; customer1.menu(); }
            else cout << "Invalid.\n";
        }

    } while (ch != 0);

    return 0;
}
