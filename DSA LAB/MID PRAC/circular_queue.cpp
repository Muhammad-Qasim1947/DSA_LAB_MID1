#include <iostream>
using namespace std;

class queue
{
private:
    int front, rear;
    int *arr;
    int cap;

public:
    queue(int c)
    {
        cap = c;
        front = -1;
        rear = -1;
        arr = new int[cap];
    }

    bool isempty()
    {
        return front == -1;
    }

    bool isfull()
    {
        return (rear + 1) % cap == front;
    }

    void enqueue(int x)
    {
        if (isfull())
        {
            cout << "Full" << endl;
            return;
        }
        if (isempty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % cap;
        }

        arr[rear] = x;
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << "Empty" << endl;
            return -1;
        }
        int x = arr[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }

        return x;
    }
};

int main()
{
}