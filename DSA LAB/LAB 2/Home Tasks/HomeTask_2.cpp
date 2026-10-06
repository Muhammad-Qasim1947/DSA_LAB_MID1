#include <iostream>
using namespace std;

// Function to insert a new mark for a student
void insertMark(int** marks, int* Size, int student, int newMark)
{
    int oldSize = Size[student];

    int* newRow = new int[oldSize + 1];

    // Copy old marks
    for (int i = 0; i < oldSize; i++)
    {
        newRow[i] = marks[student][i];
    }

    newRow[oldSize] = newMark;

    // Free old row
    delete[] marks[student];

    // Point to new row
    marks[student] = newRow;

    // Update size
    Size[student] = oldSize + 1;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int** marks = new int*[n];

    int* Size = new int[n];

    // Input marks
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << " - courses: ";
        cin >> Size[i];

        marks[i] = new int[Size[i]];

        cout << "marks: ";

        for (int j = 0; j < Size[i]; j++)
        {
            cin >> marks[i][j];
        }
    }

    double highestAverage = -1;
    double lowestAverage = 101;

    int highestStudent = 0;
    int lowestStudent = 0;

    for (int i = 0; i < n; i++)
    {
        double sum = 0;

        for (int j = 0; j < Size[i]; j++)
        {
            sum += marks[i][j];
        }

        double average = sum / Size[i];

        cout << "Student " << i + 1 << " average: "
             << average << endl;

        // Find highest
        if (average > highestAverage)
        {
            highestAverage = average;
            highestStudent = i;
        }

        // Find lowest
        if (average < lowestAverage)
        {
            lowestAverage = average;
            lowestStudent = i;
        }
    }

    cout << "Highest average: Student "
         << highestStudent + 1 << endl;

    cout << "Lowest average: Student "
         << lowestStudent + 1 << endl;

    int student, newMark;

    cout << "\nEnter student number to add a new course: ";
    cin >> student;

    cout << "Enter new mark: ";
    cin >> newMark;

    student--;

    insertMark(marks, Size, student, newMark);

    cout << "Updated marks for Student " << student + 1 << ": ";

    for (int i = 0; i < Size[student]; i++)
    {
        cout << marks[student][i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] marks[i];
    }

    delete[] marks;
    delete[] Size;

    return 0;
}