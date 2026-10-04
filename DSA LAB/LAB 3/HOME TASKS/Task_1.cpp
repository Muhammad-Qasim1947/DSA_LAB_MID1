#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0 ; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int res = j;

            while (res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = temp;
        }

        cout << "After gap " << gap << ": ";
        printArray(arr, n);
    }
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = 5;

    cout << "Original array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

//Shell Sort uses larger gaps to move elements closer to their correct positions before 
//using gap = 1. Therefore, it usually performs fewer shifts and comparisons than plain 
// Insertion Sort, even though its basic worst case complexity can still be O(n²).