#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class MatrixDimensionError : public exception {
    string _message;
public:
    MatrixDimensionError(int aRows, int aCols, int bRows, int bCols) {
        stringstream buffer;
        buffer << "DimensionMismatchException - Matrices must have same dimensions ("
               << aRows << "x" << aCols << " vs " << bRows << "x" << bCols << ")!";
        _message = buffer.str();
    }

    const char* what() const noexcept override {
        return _message.c_str();
    }
};

template <typename Type>
class MatrixHandler {
    Type** grid;
    int rowCount, colCount;

public:
    MatrixHandler(int rows, int cols) : rowCount(rows), colCount(cols) {
        grid = new Type*[rowCount];
        for (int r = 0; r < rowCount; r++)
            grid[r] = new Type[colCount];
    }

    void setElement(int r, int c, Type val) {
        grid[r][c] = val;
    }

    MatrixHandler<Type> addWith(MatrixHandler<Type>& otherMatrix) {
        if (rowCount != otherMatrix.rowCount || colCount != otherMatrix.colCount) {
            throw MatrixDimensionError(rowCount, colCount, otherMatrix.rowCount, otherMatrix.colCount);
        }

        MatrixHandler<Type> result(rowCount, colCount);
        int i = 0;
        while (i < rowCount) {
            for (int j = 0; j < colCount; j++) {
                result.grid[i][j] = grid[i][j] + otherMatrix.grid[i][j];
            }
            i++;
        }
        return result;
    }

    ~MatrixHandler() {
        for (int r = 0; r < rowCount; r++)
            delete[] grid[r];
        delete[] grid;
    }
};

int main() {
    MatrixHandler<int> firstMatrix(2, 2);
    MatrixHandler<int> secondMatrix(3, 3);
    try {
        firstMatrix.addWith(secondMatrix);
    } catch (const MatrixDimensionError& e) {
        cout << e.what() << endl;
    }
    return 0;
}