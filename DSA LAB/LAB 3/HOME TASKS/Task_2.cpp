#include <iostream>
using namespace std;

void combSort(int arr[], int n)
{
    int gap = n;
    bool swapped = true;

    int comparisons = 0;
    int swaps = 0;

    while (gap != 1 || swapped)
    {
        gap /= 1.3;

        if (gap < 1)
        {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++)
        {
            comparisons++;
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i + gap];
                arr[i + gap] = arr[i];
                arr[i] = temp;

                swaps++;
                swapped = true;
            }
        }
    }
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

void bubbleSort(int arr[], int n)
{
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    cout << "Bubble Sort Comparisons: " << comparisons << endl;
    cout << "Bubble Sort Swaps: " << swaps << endl;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[20] = {
        20, 19, 18, 17, 16,
        15, 14, 13, 12, 11,
        10, 9, 8, 7, 6,
        5, 4, 3, 2, 1};

    int arr2[20] = {
        20, 19, 18, 17, 16,
        15, 14, 13, 12, 11,
        10, 9, 8, 7, 6,
        5, 4, 3, 2, 1};

    cout << "Original Array:" << endl;
    printArray(arr1, 20);

    cout << endl
         << "Comb Sort:" << endl;
    combSort(arr1, 20);

    cout << endl
         << "Bubble Sort:" << endl;
    bubbleSort(arr2, 20);

    cout << endl
         << "Sorted Array:" << endl;
    printArray(arr1, 20);

    return 0;
}