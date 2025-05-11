#include <iostream>
#include <exception>
using namespace std;

class GeneralDatabaseError : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class FailedConnectionError : public GeneralDatabaseError {};
class QueryTimedOutError : public GeneralDatabaseError {};

template <typename Dummy>
class DBService {
public:
    void connectToDatabase(string dbName) {
        if (dbName == "invalid_db") {
            throw FailedConnectionError();
        } else if (dbName == "slow_db") {
            throw GeneralDatabaseError();
        }
    }
};

int main() {
    DBService<int> service;

    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        service.connectToDatabase("invalid_db");
    } catch (const FailedConnectionError& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        service.connectToDatabase("slow_db");
    } catch (const GeneralDatabaseError& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}