#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int iterations = 0;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        iterations++;

        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
            {
                cout << "Iterations: " << iterations << endl;
                return low;
            }
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low) /
                         (arr[high] - arr[low]));

        if (arr[pos] == key)
        {
            cout << "Iterations: " << iterations << endl;
            return pos;
        }

        if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    cout << "Iterations: " << iterations << endl;
    return -1;
}

int main()
{
    int arr[] = {
        5, 10, 15, 20, 25,
        30, 35, 40, 45, 50,
        55, 60, 65, 70, 75,
        80, 85, 90, 95, 100
    };

    int n = 20;

    cout << "Searching for 75:" << endl;
    cout << "Index: " << interpolationSearch(arr, n, 75) << endl;

    cout << endl;

    cout << "Searching for 77:" << endl;
    cout << "Index: " << interpolationSearch(arr, n, 77) << endl;

    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5, 1000};

    cout << "Searching 1000 in non-uniform array:" << endl;
    cout << "Index: " << interpolationSearch(arr2, 6, 1000) << endl;

    return 0;
}