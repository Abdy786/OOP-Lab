#include <iostream>
using namespace std;

class CustomMatrix;

class MatrixOperator {
public:
    void modify(CustomMatrix &matrix, int i, int j, int val);
};

class CustomMatrix {
private:
    int data[2][2];

public:
    CustomMatrix(int x = 0, int y = 0, int z = 0, int w = 0) {
        data[0][0] = x; data[0][1] = y;
        data[1][0] = z; data[1][1] = w;
    }

    CustomMatrix operator+(const CustomMatrix &rhs) const {
        CustomMatrix result;
        result.data[0][0] = data[0][0] + rhs.data[0][0];
        result.data[0][1] = data[0][1] + rhs.data[0][1];
        result.data[1][0] = data[1][0] + rhs.data[1][0];
        result.data[1][1] = data[1][1] + rhs.data[1][1];
        return result;
    }

    CustomMatrix operator-(const CustomMatrix &rhs) const {
        return CustomMatrix(
            data[0][0] - rhs.data[0][0], data[0][1] - rhs.data[0][1],
            data[1][0] - rhs.data[1][0], data[1][1] - rhs.data[1][1]
        );
    }

    CustomMatrix operator*(const CustomMatrix &rhs) const {
        int a = data[0][0]*rhs.data[0][0] + data[0][1]*rhs.data[1][0];
        int b = data[0][0]*rhs.data[0][1] + data[0][1]*rhs.data[1][1];
        int c = data[1][0]*rhs.data[0][0] + data[1][1]*rhs.data[1][0];
        int d = data[1][0]*rhs.data[0][1] + data[1][1]*rhs.data[1][1];
        return CustomMatrix(a, b, c, d);
    }

    friend int getDeterminant(const CustomMatrix &mat);

    friend ostream& operator<<(ostream &output, const CustomMatrix &mat) {
        output << mat.data[0][0] << " " << mat.data[0][1] << "\n";
        output << mat.data[1][0] << " " << mat.data[1][1] << "\n";
        return output;
    }

    friend class MatrixOperator;
};

int getDeterminant(const CustomMatrix &mat) {
    return (mat.data[0][0] * mat.data[1][1]) - (mat.data[0][1] * mat.data[1][0]);
}

void MatrixOperator::modify(CustomMatrix &matrix, int i, int j, int val) {
    if (i >= 0 && i < 2 && j >= 0 && j < 2) {
        matrix.data[i][j] = val;
    } else {
        cout << "Invalid indices for update!" << "\n";
    }
}

int main() {
    CustomMatrix A(0, 9, 8, 7);
    CustomMatrix B(3, 4, 5, 6);

    CustomMatrix added = A + B;
    CustomMatrix subtracted = A - B;
    CustomMatrix multiplied = A * B;

    cout << "Matrix 1:\n" << A;
    cout << "Matrix 2:\n" << B;
    cout << "Sum:\n" << added;
    cout << "Difference:\n" << subtracted;
    cout << "Product:\n" << multiplied;

    cout << "Determinant of Matrix 1: " << getDeterminant(A) << "\n";

    MatrixOperator op;
    op.modify(A, 4, 0, 3);

    cout << "Matrix 1 after update:\n" << A;

    return 0;
}
