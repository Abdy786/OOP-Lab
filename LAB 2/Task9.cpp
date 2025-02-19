#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string productName;
    int productQuantity;
    float productPrice;
};

int main() {
    int totalProducts;
    cout << "Enter the number of products: ";
    cin >> totalProducts;

    Product *productList = new Product[totalProducts];

    for (int i = 0; i < totalProducts; i++) {
        cout << "Enter the details for product [" << i + 1 << "]: " << endl;
        cout << "Product Name: ";
        cin >> productList[i].productName;
        cout << "Product ID: ";
        cin >> productList[i].productID;
        cout << "Quantity: ";
        cin >> productList[i].productQuantity;
        cout << "Price: ";
        cin >> productList[i].productPrice;
    }

    float totalInventoryValue = 0;
    for (int i = 0; i < totalProducts; i++) {
        float productValue = productList[i].productQuantity * productList[i].productPrice;
        totalInventoryValue += productValue;
    }

    cout << endl;
    cout << "The total value of the inventory is: " << totalInventoryValue << endl;

    delete[] productList;
    return 0;
}
