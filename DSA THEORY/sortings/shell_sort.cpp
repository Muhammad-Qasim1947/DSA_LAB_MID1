#include <iostream>
using namespace std;

int *shellsort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
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
    }
    return arr;
}

int main()
{
    int arr[] = {6, 3, 2, 9};
}