#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
// For a nearly-sorted array of 50 elements, I would choose Insertion Sort.
// It is fast for nearly-sorted data and uses very little extra memory.
// For a random array of 100,000 elements, I would choose Shell Sort.
// Bubble, Selection, and Insertion Sort can be slow for large random arrays.
// For an embedded system, I would choose Shell Sort because it works in-place.
// Selection Sort also uses little memory, but it is usually slower for large arrays.
// Overall, Insertion Sort is best for small data, while Shell Sort is better for large data.

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}
void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertion_sort(int *arr, int n)
{
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
    }
}

void shell_sort(int *arr, int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int key = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}
void comb_sort(int *arr, int n)
{
    int gap = n;
    bool swapped = true;
    while (swapped || gap != 1)
    {
        gap = gap / 1.3;
        swapped = false;
        if (gap < 1)
        {
            gap = 1;
        }
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}
void copy_array(int *arr, int *copy, int n)
{
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i];
    }
}
double bubbletime(int *arr, int n)
{
    int *copy = new int[n];
    copy_array(arr, copy, n);
    auto start = chrono::high_resolution_clock::now();
    bubble_sort(copy, n);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>(end - start).count();
    delete[] copy;
    return time;
}
double selectiontime(int *arr, int n)
{
    int *copy = new int[n];
    copy_array(arr, copy, n);
    auto start = chrono::high_resolution_clock::now();
    selection_sort(copy, n);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>(end - start).count();
    delete[] copy;
    return time;
}
double inserstiontime(int *arr, int n)
{
    int *copy = new int[n];
    copy_array(arr, copy, n);
    auto start = chrono::high_resolution_clock::now();
    insertion_sort(copy, n);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>(end - start).count();
    delete[] copy;
    return time;
}
double shelltime(int *arr, int n)
{
    int *copy = new int[n];
    copy_array(arr, copy, n);
    auto start = chrono::high_resolution_clock::now();
    shell_sort(copy, n);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>(end - start).count();
    delete[] copy;
    return time;
}
double combtime(int *arr, int n)
{
    int *copy = new int[n];
    copy_array(arr, copy, n);
    auto start = chrono::high_resolution_clock::now();
    comb_sort(copy, n);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration<double, milli>(end - start).count();
    delete[] copy;
    return time;
}

void test(int *arr, int n)
{
    cout << "Bubble Sort: " << bubbletime(arr, n) << " ms" << endl;
    cout << "Selection Sort: " << selectiontime(arr, n) << " ms" << endl;
    cout << "Insertion Sort: " << inserstiontime(arr, n) << " ms" << endl;
    cout << "Shell Sort: " << shelltime(arr, n) << " ms" << endl;
    cout << "Comb Sort: " << combtime(arr, n) << " ms" << endl;
}
void generate_Random(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }
}

int main()
{
    int n[] = {100, 1000, 10000, 50000};
    for (int i = 0; i < 4; i++)
    {
        cout << "For N = " << n[i] << " Time Count " << endl;
        int *arr = new int[n[i]];
        generate_Random(arr, n[i]);
        test(arr, n[i]);
        cout << endl
             << endl;
        delete[] arr;
    }

    int n1 = 10000;
    int *RandArray = new int[n1];
    generate_Random(RandArray, n1);
    int *SortedArray = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        SortedArray[i] = i;
    }
    int *ReverseArray = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        ReverseArray[i] = n1 - i;
    }
    cout << "-----For N = 10000-----" << endl;
    cout << "==Random Array==\n";
    test(RandArray, n1);
    cout << endl
         << endl;
    cout << "==Sorted Array==\n";
    test(SortedArray, n1);
    cout << endl
         << endl;
    cout << "==Reverse Array==\n";
    test(ReverseArray, n1);

    delete[] RandArray;
    delete[] SortedArray;
    delete[] ReverseArray;
}