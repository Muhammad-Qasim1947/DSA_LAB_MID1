#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int** data;

public:

    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)
        {
            return *this;
        }

        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    void set(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
    }

    int get(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            return data[r][c];
        }

        return 0;
    }

    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other)
    {
        Matrix result(rows, cols);

        if (rows == other.rows && cols == other.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
        }

        return result;
    }
};

int main()
{
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    cout << "Matrix 1:" << endl;
    m1.display();

    cout << "\nMatrix 2:" << endl;
    m2.display();

    Matrix m3 = m1 + m2;

    cout << "\nAddition:" << endl;
    m3.display();

    // Copy constructor
    Matrix m4 = m1;

    // Copy assignment
    Matrix m5(2, 2);
    m5 = m1;

    // Change m4
    m4.set(0, 0, 100);

    cout << "\nAfter changing copied matrix:" << endl;

    cout << "Original m1:" << endl;
    m1.display();

    cout << "\nCopied m4:" << endl;
    m4.display();

    cout << "\nAssigned m5:" << endl;
    m5.display();

    return 0;
}