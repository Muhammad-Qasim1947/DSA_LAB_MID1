#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* arr;
    int size;
    int capacity;

public:

    DynamicArray()
    {
        size = 0;
        capacity = 2;
        arr = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    DynamicArray(const DynamicArray& other)
    {
        size = other.size;
        capacity = other.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] arr;

        size = other.size;
        capacity = other.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    void pushBack(int value)
    {
        if (size == capacity)
        {
            capacity = capacity * 2;

            int* newArr = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        arr[size] = value;
        size++;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index" << endl;
            return arr[0];
        }

        return arr[index];
    }

    void print() const
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
    DynamicArray a;

    a.pushBack(10);
    a.pushBack(20);
    a.pushBack(30);
    a.pushBack(40);
    a.pushBack(50);
    a.pushBack(60);

    cout << "Original array: ";
    a.print();

    DynamicArray b = a;

    b[0] = 100;

    cout << "After modifying copy:" << endl;

    cout << "Original: ";
    a.print();

    cout << "Copy: ";
    b.print();

    return 0;
}