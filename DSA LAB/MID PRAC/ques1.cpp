#include <iostream>
using namespace std;

class assignment
{
public:
    int due;
    string name;

    assignment()
    {
        due = 0;
        name = ' ';
    }

    assignment(int d, string n) : due(d), name(n) {}

    string getName() const { return name; }
    int getDue() const { return due; }

    void display() const
    {
        cout << name << " (" << due << " Oct)  ";
    }
};

void selection_sort(assignment arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].getDue() > arr[minindex].getDue())
            {
                minindex = j;
            }
        }
        assignment temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int binary_search(assignment arr[], int n, int due)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid].getDue() < due)
        {
            high = mid - 1;
        }
        else if (arr[mid].getDue() > due)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    assignment drawer[5] = {
        assignment(9, "A"),
        assignment(7, "B"),
        assignment(5, "C"),
        assignment(15, "D"),
        assignment(2, "E")
    };

    cout << "Before sorting: ";
    for (int i = 0; i < 5; i++)
        drawer[i].display();
    cout << endl;

    selection_sort(drawer, 5);

    cout << "After sorting : ";
    for (int i = 0; i < 5; i++)
        drawer[i].display();
    cout << endl;

    int tests[] = {7, 5, 10};
    for (int i = 0; i < 3; i++)
    {
        int pos = binary_search(drawer, 5, tests[i]);
        if (pos == -1)
            cout << "Due " << tests[i] << " Oct: Not found (-1)" << endl;
        else
            cout << "Due " << tests[i] << " Oct: found at position " << pos
                 << " (" << drawer[pos].getName() << ")" << endl;
    }
    return 0;
}