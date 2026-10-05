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
    }
}

int main()
{
    int n;
    cout << "Enter Number Of Shelves : ";
    cin >> n;

    int *shelf = new int[n];

    cout << "Enter Book Capacity Of Each Shelf : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> shelf[i];
    }

    int pos;
    cout << "Enter Position To Add New Shelf (0 to " << n << ") : ";
    cin >> pos;

    int capacity;
    cout << "Enter Capacity Of The New Shelf : ";
    cin >> capacity;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid position!" << endl;
        delete[] shelf;
        return 1;
    }

    int newsize = n + 1;
    int *newshelf = new int[newsize];

    for (int i = 0; i < pos; i++)
    {
        newshelf[i] = shelf[i];
    }

    newshelf[pos] = capacity;

    for (int i = pos ; i < n; i++)
    {
        newshelf[i+1] = shelf[i];
    }

    cout << endl;
    cout << "Original Shelf Capacities :";
    displayArray(shelf, n);

    cout << "Shelves After Adding New Shelf :";
    displayArray(newshelf, newsize);

    insertion(newshelf, newsize);
    
    cout << "Shelves After Sorting:";

    displayArray(newshelf, newsize);

    delete[] shelf ;
    delete[] newshelf ;

    return 0 ;
}