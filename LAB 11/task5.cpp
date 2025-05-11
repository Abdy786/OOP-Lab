#include <iostream>
#include <exception>
using namespace std;

class StockNegativeError : public exception {};
class StockLimitExceededError : public exception {};

template <typename StockType>
class StockManager {
    StockType currentStock;
    const StockType maxStock;

public:
    StockManager(StockType limit) : currentStock(0), maxStock(limit) {}

    void updateStock(StockType amount) {
        if (amount < 0) {
            throw StockNegativeError();
        }
        if (amount > maxStock) {
            throw StockLimitExceededError();
        }
        currentStock = amount;
    }
};

int main() {
    StockManager<int> warehouse(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        warehouse.updateStock(-5);
    } catch (const StockNegativeError& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        warehouse.updateStock(120);
    } catch (const StockLimitExceededError& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}