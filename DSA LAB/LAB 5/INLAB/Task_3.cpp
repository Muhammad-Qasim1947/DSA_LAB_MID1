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

int precedence(char c)
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

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

bool validParentheses(char infix[])
{
    int count = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            count++;
        }
        else if (infix[i] == ')')
        {
            count--;

            if (count < 0)
            {
                return false;
            }
        }
    }

    return count == 0;
}

void infixtopostfix(char infix[], char postfix[], int size)
{
    Stack s(size);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }

            s.pop();
        }
        else if (isOperator(ch))
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                    (precedence(s.peek()) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    cout << "Input: ";
    cin >> infix;

    if (!validParentheses(infix))
    {
        cout << "Invalid Expression" << endl;
    }
    else
    {
        infixtopostfix(infix, postfix, 100);
        cout << "Output: " << postfix << endl;
    }

    return 0;
}