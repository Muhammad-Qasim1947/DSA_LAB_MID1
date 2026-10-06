#include <iostream>
using namespace std;

int bubblesortcount = 0;
int selectionsortcount = 0;
int insertionsortcount = 0;
int binarysearchcount = 0;
int linearsearchcount = 0;

void bubblesort(int *arr, int n)
{
    bubblesortcount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bubblesortcount++;
            }
        }
    }
}

void selectionsort(int *arr, int n)
{
    selectionsortcount = 0;
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
            selectionsortcount++;
        }
    }
}

void insertionsort(int *arr, int n)
{
    insertionsortcount = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        insertionsortcount++;
    }
}

int binarysearch(int *arr, int key, int n)
{
    binarysearchcount = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        binarysearchcount++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int linearsearch(int *arr, int key, int n)
{
    linearsearchcount = 0;
    for (int i = 0; i < n; i++)
    {
        linearsearchcount++;
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void displayArray(int *arr, int n, const string &label)
{
    cout << "\n" << label << " : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int *src, int *dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
}

int main()
{
    int n;
    cout << "Enter Number Of Elements In Array : ";
    cin >> n;

    int *originalarr = new int[n];
    int *sortedarr = new int[n];  
    bool isSorted = false;

    cout << "Enter " << n << " Elements In Array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> originalarr[i];
    }
    copyArray(originalarr, sortedarr, n);

    int choice;
    do
    {
        cout << "\n===================== MENU =====================" << endl;
        cout << "1. Sort The Array (Bubble / Selection / Insertion)" << endl;
        cout << "2. Search Using Binary Search (On Sorted Array)" << endl;
        cout << "3. Search Using Linear Search (On Original Unsorted Array)" << endl;
        cout << "4. Display Current Array And Exit" << endl;
        cout << "==================================================" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // sort a fresh copy of the original array so it always sorts
            // from the unsorted data, not from a previously sorted state
            copyArray(originalarr, sortedarr, n);

            int algoChoice;
            cout << "\nChoose Sorting Algorithm :" << endl;
            cout << "1. Bubble Sort" << endl;
            cout << "2. Selection Sort" << endl;
            cout << "3. Insertion Sort" << endl;
            cout << "Enter Choice : ";
            cin >> algoChoice;

            switch (algoChoice)
            {
            case 1:
                bubblesort(sortedarr, n);
                displayArray(sortedarr, n, "Array After Bubble Sort");
                cout << "Bubble Sort Count : " << bubblesortcount << endl;
                break;
            case 2:
                selectionsort(sortedarr, n);
                displayArray(sortedarr, n, "Array After Selection Sort");
                cout << "Selection Sort Count : " << selectionsortcount << endl;
                break;
            case 3:
                insertionsort(sortedarr, n);
                displayArray(sortedarr, n, "Array After Insertion Sort");
                cout << "Insertion Sort Count : " << insertionsortcount << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
                continue;
            }
            isSorted = true;
            break;
        }

        case 2:
        {
            if (!isSorted)
            {
                cout << "\nArray Is Not Sorted Yet! Please Use Option 1 First." << endl;
                break;
            }
            int key;
            cout << "\nEnter Element To Search (Binary Search) : ";
            cin >> key;

            int result = binarysearch(sortedarr, key, n);

            if (result != -1)
            {
                cout << "Element " << key << " Found At Index : " << result << endl;
            }
            else
            {
                cout << "Element " << key << " Not Found" << endl;
            }
            cout << "Binary Search Comparisons : " << binarysearchcount << endl;
            break;
        }

        case 3:
        {
            int key;
            cout << "\nEnter Element To Search (Linear Search) : ";
            cin >> key;

            int result = linearsearch(originalarr, key, n);

            if (result != -1)
            {
                cout << "Element " << key << " Found At Index : " << result << endl;
            }
            else
            {
                cout << "Element " << key << " Not Found" << endl;
            }
            cout << "Linear Search Comparisons : " << linearsearchcount << endl;
            break;
        }

        case 4:
        {
            displayArray(originalarr, n, "Original (Unsorted) Array");
            if (isSorted)
            {
                displayArray(sortedarr, n, "Sorted Array");
            }
            cout << "\nExiting Program..." << endl;
            break;
        }

        default:
            cout << "Invalid Choice! Please Enter 1-4." << endl;
        }

    } while (choice != 4);

    // ========= Delete Memory =========
    delete[] originalarr;
    delete[] sortedarr;

    return 0;
}