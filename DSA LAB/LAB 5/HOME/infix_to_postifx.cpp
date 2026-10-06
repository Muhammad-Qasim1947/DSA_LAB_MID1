#include <iostream>
using namespace std ;


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

string infixtopostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                char op = s.pop();
                postfix += op;
            }
            if (s.peek() == '(')
            {
                s.pop();
            }
        }
        else
        {
            while (!s.isEmpty() && getprecedence(c) <= getprecedence(s.peek()))
            {
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        char op = s.pop();
        postfix += op;
    }
    return postfix;
}
