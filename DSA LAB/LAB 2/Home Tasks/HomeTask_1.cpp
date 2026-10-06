// 25K-0608 Muhammad Qasim
#include <iostream>
using namespace std;

class SafeMatric
{
private:
    int rows, cols;
    int **data;

public:
    SafeMatric(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;

        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    void set(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error" << endl;
            return;
        }
        data[r][c] = val;
    }

    int get(int r, int c)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            cout << "Boundary Error" << endl;
            return -1;
        }
        return data[r][c];
    }

    void display()
    {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    ~SafeMatric()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        cout << "Matrix memory freed successfully." << endl;
    }
};

int main()
{
    SafeMatric safemat(4,4);

    // Fill matrix via set() with valid values
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            safemat.set(i, j, counter++);
        }
    }

    // Display the matrix
    safemat.display();

    cout << "\n--- Demonstrating invalid accesses ---\n" << endl;

    // Invalid access 1: negative row
    cout << "Attempting set(-1, 2, 99): ";
    safemat.set(-1, 2, 99);

    // Invalid access 2: column out of range
    cout << "Attempting get(1, 10): ";
    int val = safemat.get(1, 10);
    cout << "Returned value: " << val << endl;

    // Invalid access 3
    cout << "Attempting set(4, 0, 55): ";
    safemat.set(4, 0, 55);

    // Matrix is unchanged after invalid attempts
    cout << "\nMatrix after invalid access attempts (unchanged):" << endl;
    safemat.display();

    return 0;
}