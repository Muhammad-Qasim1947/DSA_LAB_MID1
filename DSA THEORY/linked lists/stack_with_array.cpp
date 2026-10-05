#include <iostream>
using namespace std;

class stack
{
private:
    int top = -1;
    int capacity;
    int *sk;

public:
    stack(int c) : top(-1), capacity(c)
    {
        sk = new int[capacity];
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == 9)
        {
            return true;
        }
        return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is Full!" << endl;
            return;
        }
        else
        {
            top++;
            sk[top] = val;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Already Empty!" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return sk[top];
    }

    void print()
    {
        if (top == -1)
        {

            cout << "Stack Empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << sk[i] << endl;
        }
    }

    ~stack()
    {
        delete[] sk;
    }
};

int main()
{

    stack sk(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    sk.push(10);
    // sk.push(10);
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.pop();
    sk.push(100);

    sk.print();
}