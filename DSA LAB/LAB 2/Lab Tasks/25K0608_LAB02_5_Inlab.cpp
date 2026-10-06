#include <iostream>
using namespace std;

int main()
{
    int rows;

    cout << "Enter number of Rows: ";
    cin >> rows;

    int** arr = new int*[rows];
    int* Size = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter size of Row " << i + 1 << ": ";
        cin >> Size[i];

        arr[i] = new int[Size[i]];
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter " << Size[i] << " elements for Row " << i + 1 << ": ";

        for (int j = 0; j < Size[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "\nJagged Array Elements:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i + 1 << ": ";

        for (int j = 0; j < Size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nRow Sums and Averages:\n";

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;

        for (int j = 0; j < Size[i]; j++)
        {
            sum += arr[i][j];
        }

        double average = (double)sum / Size[i];

        cout << "Row " << i + 1 << ": ";
        cout << "Sum = " << sum;
        cout << ", Average = " << average << endl;
    }

    int most = 0;
    int fewest = 0;

    for (int i = 1; i < rows; i++)
    {
        if (Size[i] > Size[most])
        {
            most = i;
        }

        if (Size[i] < Size[fewest])
        {
            fewest = i;
        }
    }

    cout << "\nRow with most elements: Row " << most + 1 << endl;
    cout << "Row with fewest elements: Row " << fewest + 1 << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] Size;

    return 0;
}