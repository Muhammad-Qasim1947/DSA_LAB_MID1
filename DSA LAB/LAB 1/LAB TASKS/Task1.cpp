#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Dynamic array
    int* arr = new int[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Initialize
    int sum = 0;
    int maximum = arr[0];
    int minimum = arr[0];

    // Calculate sum, maximum and minimum
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (arr[i] > maximum)
            maximum = arr[i];

        if (arr[i] < minimum)
            minimum = arr[i];
    }

    double average = (double)sum / n;

    // Output
    cout << endl ;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    // Free memory
    delete[] arr;
    return 0;
}