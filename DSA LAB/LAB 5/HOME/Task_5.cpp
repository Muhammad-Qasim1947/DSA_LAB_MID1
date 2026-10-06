#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    bool isempty()
    {
        return top == NULL;
    }

    void push(int d)
    {
        node *newnode = new node(d);

        newnode->next = top;
        top = newnode;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        node *temp = top;
        int val = temp->data;
        top = temp->next;
        temp->next = NULL;
        delete temp;
        return val;
    }

    int peek()
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
        }
        return top->data;
    }
};

class queue
{
public:
    stack stackin;
    stack stackout;

    void enqueue(int d)
    {
        stackin.push(d);
    }

    int dequeue()
    {
        if (!stackout.isempty())
        {
            return stackout.pop();
        }
        else
        {
            while (!stackin.isempty())
            {
                int n = stackin.pop();
                stackout.push(n);
            }
        }
        return stackout.pop();
    }
};

int main()
{
    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeue: " << q.dequeue() << endl;

    q.enqueue(4);

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    return 0;
}