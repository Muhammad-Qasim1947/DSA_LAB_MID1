#include <iostream>
using namespace std;

void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > arr[curr])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void selectionsort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestidx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestidx])
            {
                smallestidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestidx];
        arr[smallestidx] = temp;
    }
}

void combsort(int *arr, int n)
{
    bool swap = true;
    int gap = n;

    while (gap > 1 || swap)
    {
        gap /= 1.3;

        cout << "Gap = " << gap << endl;

        if (gap < 1)
        {
            gap = 1;
        }

        swap = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i + gap];
                arr[i + gap] = arr[i];
                arr[i] = temp;

                swap = true;
            }
        }
    }
}

void shellsort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int res = i;
            while (res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = temp;
        }
    }
}

int main()
{
    int arr[] = {2, 6, 9, 1, 5, 0, 6, 7};
    int n = 8;
}