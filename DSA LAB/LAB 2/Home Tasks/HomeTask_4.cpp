// 25K-0608 Muhammad Qasim
#include <iostream>
using namespace std;

class DynamicSafeArray
{
private:
    int* arr;
    int capacity;
    int count;

public:
    DynamicSafeArray(int initialCapacity)
    {
        capacity = initialCapacity;
        count = 0;

        arr = new int[capacity];
    }

    // Push a new element
    void pushBack(int val)
    {
        if (count == capacity)
        {
            int newCapacity = capacity * 2;

            int* newArr = new int[newCapacity];

            // Copy old elements
            for (int i = 0; i < count; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;

            arr = newArr;

            capacity = newCapacity;

            cout << "Array resized to capacity: "
                 << capacity << endl;
        }

        // Insert new element
        arr[count] = val;
        count++;
    }

    void set(int pos, int val)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Boundary Error: Invalid position!" << endl;
            return;
        }

        arr[pos] = val;
    }

    int get(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Boundary Error: Invalid position!" << endl;
            return -1;
        }

        return arr[pos];
    }

    bool removeAt(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Boundary Error: Invalid position!" << endl;
            return false;
        }

        for (int i = pos; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        count--;

        return true;
    }

    void display()
    {
        cout << "Array: ";

        for (int i = 0; i < count; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~DynamicSafeArray()
    {
        delete[] arr;
    }
};


int main()
{
    DynamicSafeArray a(2);

    a.pushBack(10);
    a.pushBack(20);

    a.pushBack(30);   

    a.pushBack(40);
    a.pushBack(50);
    a.pushBack(60);

    a.display();

    cout << "\nRemoving element at position 2..." << endl;

    a.removeAt(2);

    a.display();

    cout << "\nElement at position 1: "
         << a.get(1) << endl;

    cout << "\nTrying to get position 10:" << endl;
    a.get(10);

    cout << "\nTrying to set position 10:" << endl;
    a.set(10, 999);

    return 0;
}