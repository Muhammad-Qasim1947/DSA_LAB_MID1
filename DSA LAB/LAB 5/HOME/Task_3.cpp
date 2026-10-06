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

bool isoperand(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isBalanced(string expr)
{
    Stack s(expr.length());

    for (int i = 0; i < expr.length(); i++)
    {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
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
    string tests[] = {"{A+(B*C)-[D/E]}", "{A+(B*C)-[D/E]", "(A+B]"};

    for (int i = 0; i < 3; i++)
    {
        cout << "Input: " << tests[i] << endl;
        if (isBalanced(tests[i]))
            cout << "Output : Balanced" << endl;
        else
            cout << "Output : Not Balanced" << endl;
    }

    return 0 ;
}
