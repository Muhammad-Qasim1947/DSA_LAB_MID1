#include <iostream>
using namespace std;

class customer
{
public:
    string name;
    int month;
    int day;
    int hanger;

    customer()
    {
        name = "";
        day = 0;
        month = 0;
        hanger = 0;
    }

    customer(string n, int d, int m)
    {
        day = d;
        month = m;
        name = n;
        hanger = 0;
    }
};

bool isfirst(customer a, customer b)
{
    if (a.month != b.month)
    {
        return a.month < b.month;
    }

    if (a.day != b.day)
    {
        return a.day < b.day;
    }

    return a.name.length() > b.name.length();
}

void selection_sort(customer arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; i < n; j++)
        {
            if (isfirst(arr[j], arr[i]))
            {
                minindex = j;
            }
        }
        customer temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int pos = i - 1;

        while (pos >= 0 && arr[pos] > key)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = key;
    }
}

void shell_sort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[gap];
            int res = j;
            while (res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = temp;
        }
    }
}

int binarysearch(customer arr[], int n, string name)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid].name == name)
        {
            return arr[mid].hanger;
        }
        else if (arr[mid].name < name)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        if (arr[low] == arr[high])
        {
            if (arr[low] == key)
                return low;
            return -1;
        }
        int pos = low + ((key - arr[low]) * (high - low) / arr[high] - arr[low]);

        if (arr[pos] == key)
        {
            return pos;
        }
        else if (arr[pos] < key)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
}

int main()
{
    customer customers[5] =
        {
            customer("Mubeen", 9, 9),
            customer("Ali", 1, 9),
            customer("Shaheer", 15, 9),
            customer("Sadiq", 8, 9),
            customer("Romaan", 20, 9)
        };

    int n = 5;

    selection_sort(customers, n);

    // Assign hanger numbers
    for (int i = 0; i < n; i++)
    {
        customers[i].hanger = i + 1;
    }

    cout << "Sorted Customers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << customers[i].name
             << " - Hanger " << customers[i].hanger << endl;
    }

    string searchName;

    cout << "\nEnter customer name: ";
    cin >> searchName;

    int result = binarysearch(customers, n, searchName);

    if (result == -1)
        cout << "Customer not found" << endl;
    else
        cout << "Hanger Number: " << result << endl;

    return 0;
}