// Matrix multiplication using pointers
#include <iostream>
using namespace std;

int main()
{
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows for Matrix A: ";
    cin >> rowsA;
    cout << "Enter the number of columns for Matrix A: ";
    cin >> colsA;
    cout << "Enter the number of rows for Matrix B: ";
    cin >> rowsB;
    cout << "Enter the number of columns for Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible! The number of columns in Matrix A must match the number of rows in Matrix B." << endl;
        return 0;
    }

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

    cout << "Enter elements for Matrix A: " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements for Matrix B: " << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }

    int **matrixC = new int *[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixC[i] = new int[colsB];
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            matrixC[i][j] = 0;
        }
    }

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Resultant Matrix after multiplication: " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rowsA; i++)
    {
        delete[] matrixA[i];
    }
    delete[] matrixA;

    for (int i = 0; i < rowsB; i++)
    {
        delete[] matrixB[i];
    }
    delete[] matrixB;

    for (int i = 0; i < rowsA; i++)
    {
        delete[] matrixC[i];
    }
    delete[] matrixC;

    return 0;
}
