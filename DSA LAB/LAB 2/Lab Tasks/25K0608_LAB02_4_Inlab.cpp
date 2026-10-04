#include <iostream>
using namespace std;

class SafeArray
{
private:
    int* arr;
    int size;

public:

    SafeArray(int s)
    {
        size = s;
        arr = new int[size];
    }

    ~SafeArray()
    {
        delete[] arr;
    }

    void set(int pos, int val)
    {
        if (pos >= 0 && pos < size)
        {
            arr[pos] = val;
        }
        else
        {
            cout << "Boundary Error" << endl;
        }
    }

    int get(int pos)
    {
        if (pos >= 0 && pos < size)
        {
            return arr[pos];
        }
        else
        {
            cout << "Boundary Error" << endl;
            return -1;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    SafeArray arr(5);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);
    arr.set(3, 40);
    arr.set(4, 50);

    cout << "Array: ";
    arr.display();

    cout << "Value at position 2: " << arr.get(2) << endl;

    arr.set(10, 100);
    arr.set(-1, 200);

    cout << "Value at position 10: " << arr.get(10) << endl;
    cout << "Value at position -1: " << arr.get(-1) << endl;

    return 0;
}
