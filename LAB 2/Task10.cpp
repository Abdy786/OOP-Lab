#include <iostream>
using namespace std;

int main() {
    int depth, rows, cols;
    cout << "Enter the dimensions of the 3D array (depth rows cols): ";
    cin >> depth >> rows >> cols;

    int ***threeDArray = new int **[depth];
    for (int i = 0; i < depth; i++) {
        threeDArray[i] = new int *[rows];
        for (int j = 0; j < rows; j++) {
            threeDArray[i][j] = new int[cols];
        }
    }

    cout << "Enter " << (depth * rows * cols) << " integers: " << endl;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                cin >> threeDArray[i][j][k];
            }
        }
    }

    cout << "3D Array elements:" << endl;
    for (int i = 0; i < depth; i++) {
        cout << "Layer " << i + 1 << ":" << endl;
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                cout << threeDArray[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] threeDArray[i][j];
        }
        delete[] threeDArray[i];
    }
    delete[] threeDArray;

    return 0;
}
