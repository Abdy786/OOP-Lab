#include <iostream>
using namespace std;

int main() {
    int elementCount;
    cout << "Enter the number of elements: ";
    cin >> elementCount;

    int **pointerArray = new int *[elementCount];

    for (int i = 0; i < elementCount; i++) {
        pointerArray[i] = new int;
    }

    for (int i = 0; i < elementCount; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> *pointerArray[i];
    }

    cout << "Array elements:" << endl;
    for (int i = 0; i < elementCount; i++) {
        cout << *pointerArray[i] << endl;
    }

    for (int i = 0; i < elementCount; i++) {
        delete pointerArray[i];
    }
    delete[] pointerArray;

    return 0;
}
