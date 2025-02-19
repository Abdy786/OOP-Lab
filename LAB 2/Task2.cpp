// Pointer to Pointer for matrix operations
#include <iostream>
using namespace std;

int main()
{
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter the number of rows for the first matrix: ";
    cin >> rowsA;
    cout << "Enter the number of columns for the first matrix: ";
    cin >> colsA;
    cout << "Enter the number of rows for the second matrix: ";
    cin >> rowsB;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> colsB;

    int **matrixA = new int *[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new int[colsA];
    }
    int **matrixB = new int *[rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new int[colsB];
    }
    cout << "Enter the first matrix's elements: " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << "Enter the [" << i << "][" << j << "]th element: ";
            cin >> matrixA[i][j];
        }
    }
    cout << "Enter the second matrix's elements: " << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter the [" << i << "][" << j << "]th element: ";
            cin >> matrixB[i][j];
        }
    }
    if (rowsA == rowsB && colsA == colsB)
    {
        int sumMatrix[rowsA][colsA];
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
        int diffMatrix[rowsA][colsA];
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                diffMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
        cout << "Matrix Addition: " << endl;
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                cout << sumMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Matrix Subtraction: " << endl;
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                cout << diffMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The matrices cannot be added or subtracted because their dimensions do not match.";
    }
    
    for (int i = 0; i < rowsA; i++)
        delete[] matrixA[i];
    delete[] matrixA;
    
    for (int i = 0; i < rowsB; i++)
        delete[] matrixB[i];
    delete[] matrixB;
    
    return 0;
}
