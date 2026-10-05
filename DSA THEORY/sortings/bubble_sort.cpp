#include <iostream>
using namespace std;

int *bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int *selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        if (minindex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
    return arr;
}

int *insertionsort(int arr[], int n){
    for (int i = 1 ; i < n ; i++)
    {
        int current = arr[i] ;
        int prev = i - 1 ;
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev-- ;
        }
        arr[prev + 1] = current ;
    }
    

}

int main()
{
    int *arr = new int[10];
    int *selectionarr = new int[10];
    int *insertionarr = new int[10];
    int *shellarr = new int[10];

    cout << "Enter 10 Elements In Array : " << endl;

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        selectionarr[i] = arr[i];
        insertionarr[i] = arr[i];
        shellarr[i] = arr[i];
    }

    cout << "Array Elements Entered : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    // =========Bubble_Sort=========
    int *sortarray = bubblesort(arr, 10);

    cout << "\nArray After Bubble Sort : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    // =========Selection_Sort=========
    int *Selectionsort = selectionsort(selectionarr, 10);

    cout << endl;

    cout << "\nArray After Selection Sort : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << selectionarr[i] << " ";
    }

        // =========Insertion_Sort=========
    int *Insertionsort = insertionsort(insertionarr, 10);

    cout << endl;

    cout << "\nArray After Insertion Sort : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << insertionarr[i] << " ";
    }


}