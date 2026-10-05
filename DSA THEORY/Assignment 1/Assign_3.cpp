#include <iostream>
using namespace std;

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void combsort(int *arr, int n)
{
    int gap = n;
    bool swapped = true;
    int pass = 1;

    while (gap != 1 || swapped == true)
    {
        gap /= 1.3;

        cout << "Gap = " << gap << endl;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i < n - gap; i++) // 6 - 4 = 2
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i + gap];
                arr[i + gap] = arr[i];
                arr[i] = temp;

                swapped = true;
            }
        }
        cout << "Pass " << pass++ << " (Gap = " << gap << ") : ";
        displayArray(arr, n);
    }
}

int main()
{
    int n;
    cout << "Enter Number Of Package Weights : ";
    cin >> n;

    int *package = new int[n];

    cout << "Enter Package Weights : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> package[i];
    }

    cout << "\nOriginal Array : ";
    displayArray(package, n);
    cout << "----------------------------------------" << endl;

    combsort(package, n);

    cout << "----------------------------------------" << endl;
    cout << "Final Sorted Array : ";
    displayArray(package, n);

    delete[] package;

    return 0 ;
}