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

string infixtopostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isoperand(c))
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
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
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

string infixtoprefix(string infix)
{
    string prefix = "";
    Stack s(infix.length());

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];
        if (isoperand(c))
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
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
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

bool isBalanced(string infix)
{
    Stack s(infix.length());
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.isEmpty())
            {
                return false;
            }
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main()
{
    string tests[] = {
        "A+B*C",
        "(A+B)*(C-D)",
        "A+B*(C^D-E)",
        "(A+B"
    };

    for (int i = 0; i < 4; i++)
    {
        cout << "Infix   : " << tests[i] << endl;
        if (!isBalanced(tests[i]))
        {
            cout << "Invalid: parentheses not balanced\n" << endl;
            continue;
        }
        cout << "Postfix : " << infixtopostfix(tests[i]) << endl;
        cout << "Prefix  : " << infixtoprefix(tests[i]) << "\n"
             << endl;
    }
    return 0;
}