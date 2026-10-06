#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char *arr;
    int topIdx;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new char[capacity];
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

    void push(char c)
    {
        if (isFull())
        {
            cout << "Full Stack" << endl;
            return;
        }

        arr[++topIdx] = c;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }

        return arr[topIdx--];
    }

    char peek() const
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

int precedence(int c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '-' || c == '+')
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

int postfixevaluator(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
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
                {
                    return -1;
                }
                else
                {
                    result = a / b;
                }
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
    string tests[] = {
        "23*54*+",
        "62/",
        "9+"};

    for (int i = 0; i < 3; i++)
    {
        int result = postfixevaluator(tests[i]);

        if (result == -1)
            cout << "Output: Error: Malformed expression";
        else
            cout << "Output: " << result;
            cout << endl ;
    }
    return 0 ;
}