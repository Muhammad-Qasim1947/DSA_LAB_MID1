#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int topIdx;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        topIdx = -1;
    }

    bool isEmpty() const
    {
        return topIdx == -1;
    }

    bool isFull() const
    {
        return topIdx == capacity - 1;
    }

    void push(int c)
    {
        if (isFull())
        {
            cout << "Full Stack" << endl;
            return;
        }

        arr[++topIdx] = c;
    }

    int pop()
    {
        if (isEmpty())
        {
            return '\0';
        }

        return arr[topIdx--];
    }

    int peek() const
    {
        if (isEmpty())
        {
            return '\0';
        }

        return arr[topIdx];
    }

    ~Stack()
    {
        delete[] arr;
    }

    int size()
    {
        return topIdx + 1;
    }
};

int getprecedence(int c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isoperand(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

int postfixevaluator(string exp)
{
    Stack s(exp.length());

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (c >= '0' && c <= '9')
        {
            s.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            if (s.size() < 2)
            {
                return -1;
            }

            int b = s.pop();
            int a = s.pop();
            int result;

            if (c == '+')
            {
                result = a + b;
            }
            else if (c == '-')
            {
                result = a - b;
            }
            else if (c == '*')
            {
                result = a * b;
            }
            else
            {
                if (b == 0)
                    return -1;

                result = a / b;
            }
            s.push(result);
        }
    }
    if (s.size() != 1)
    {
        return -1;
    }

    return s.pop();
}

int main()
{
    string exp;

    cout << "Input: ";
    cin >> exp;

    int result = postfixevaluator(exp);

    if (result == -1)
        cout << "Output: Error: Malformed expression";
    else
        cout << "Output: " << result;

    return 0;
}