#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }
    return mat;
}

void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void readMatrix(int** mat, int rows, int cols, const string& name) {
    cout << "Enter elements for matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << name << "[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrices(int** A, int rows1, int cols1, int** B, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Error: Matrix dimensions do not match for addition." << endl;
        return;
    }

    int** result = allocateMatrix(rows1, cols1);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nResult of A + B:" << endl;
    displayMatrix(result, rows1, cols1);

    freeMatrix(result, rows1);
}

void multiplyMatrices(int** A, int rows1, int cols1, int** B, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "Error: cols of A must equal rows of B for multiplication." << endl;
        return;
    }

    int** result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult of A x B:" << endl;
    displayMatrix(result, rows1, cols2);

    freeMatrix(result, rows1);
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter rows and cols for matrix A: ";
    cin >> rows1 >> cols1;
    int** A = allocateMatrix(rows1, cols1);
    readMatrix(A, rows1, cols1, "A");

    cout << "Enter rows and cols for matrix B: ";
    cin >> rows2 >> cols2;
    int** B = allocateMatrix(rows2, cols2);
    readMatrix(B, rows2, cols2, "B");

    int choice;
    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Add matrices" << endl;
        cout << "2. Multiply matrices" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMatrices(A, rows1, cols1, B, rows2, cols2);
                break;
            case 2:
                multiplyMatrices(A, rows1, cols1, B, rows2, cols2);
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    freeMatrix(A, rows1);
    freeMatrix(B, rows2);

    return 0;
}