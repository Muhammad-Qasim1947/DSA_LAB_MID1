#include <iostream>
#include <string>
using namespace std;

class stack
{
    string *arr;
    int top;
    int cap;

public:
    stack(int c)
    {
        cap = c;
        arr = new string[cap];
        top = -1;
    }

    bool isempty()
    {
        return top == -1;
    }

    bool isfull()
    {
        return top == cap - 1;
    }

    void push(string d)
    {
        if (isfull())
        {
            cout << "Full Stack" << endl;
            return;
        }

        top++;
        arr[top] = d;
        cout << "" << d << " Pushed Into Stack" << endl;
    }

    string pop()
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
            return "";
        }

        string value = arr[top];
        top--;
        cout << "" << value << " Popped From Stack" << endl;
        return value;
    }

    void display()
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
            return;
        }

        cout << "Pending Tasks (Top To Bottom) : " << endl;
        int j=1;
        for (int i = top; i >= 0; i--)
        {
            cout << "" << j++ << ". " << arr[i] << " ";
        }
        cout << endl;
    }

    void search(string task)
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
            return;
        }

        int above = 0;

        for (int i = top; i >= 0; i--)
        {
            if (arr[i] == task)
            {
                cout << task << " Found!" << endl;
                cout << "Tasks above it: " << above << endl;
                return;
            }

            above++;
        }

        cout << task << " Not Found" << endl;
    }
};

int main()
{
    int c;
    string t;
    stack s(10);
    string sear;

    do
    {
        cout << "1. Add Task 2. Remove Last Task 3. View All 4. Search 5. Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter Task : ";
            getline(cin >> ws, t);
            s.push(t);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Enter Task To Search : ";
            getline(cin >> ws, sear);
            s.search(sear);
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (c != 5);
}