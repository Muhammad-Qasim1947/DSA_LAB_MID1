#include <iostream>
using namespace std;

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;

        cout << endl;

        cout << "Array After " << i << " Iteration : " << endl;
        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter The Number Of Cable Lengths : " << endl;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size." << endl;
        return 0;
    }

    int *arr = new int[n];

    cout << "Enter " << n << " cable lengths:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Length " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nArray Before Insertion Sort : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    insertion(arr, n);

    cout << endl;

    cout << "\nArray After Insertion Sort : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}