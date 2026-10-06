#include <iostream>
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

string infixtoprefix(string infix)
{
    string prefix = "";
    Stack s(infix.length());

    for (int i = infix.length(); i >= 0; i--)
    {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            prefix = c + prefix;
        }
        else if (c == ')')
        {
            s.push(c);
        }
        else if (c == '(')
        {
            while (!s.isEmpty() && s.peek() != ')')
            {
                char op = s.pop();
                prefix = op + prefix;
            }
            if (s.peek() == ')')
            {
                s.pop();
            }
        }
        else
        {
            while (!s.isEmpty() && getprecedence(c) <= getprecedence(s.peek()))
            {
                char op = s.pop();
                prefix = op + prefix;
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        char op = s.pop();
        prefix = op + prefix;
    }
    return prefix;
}

int main()
{
    string tests[] = {"A+B*C", "(A+B)*(C-D)", "A+B*(C^D-E)"};

    for (int i = 0; i < 3; i++)
    {
        cout << "Input: " << tests[i] << endl;
        cout << "Output: " << infixtoprefix(tests[i]) << endl;
    }

    return 0;
}