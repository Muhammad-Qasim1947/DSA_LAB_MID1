#include <iostream>
using namespace std;
#define MAX 100

class stack
{
public:
    int arr[MAX];
    int top;

    stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        return arr[top--];
    }
};

class queue
{
public:
    stack s1, s2;

    void enqueue(int x)
    {
        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        s1.push(x);
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }

    int dequeue()
    {
        return s1.pop();
    }
};

int main()
{
}