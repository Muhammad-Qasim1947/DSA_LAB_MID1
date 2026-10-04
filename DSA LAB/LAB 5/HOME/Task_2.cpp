/*
 * In a linear queue, 'rear' only moves forward and never wraps around.
 * Dequeue just advances 'front', so the freed slots at the start of the
 * array are never reused; once rear reaches cap-1 the queue reports "full"
 * even though slots before 'front' are empty. A circular queue fixes this by
 * wrapping indices with modulo (index = (index + 1) % cap), so freed slots
 * at the front are reused.
 */

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
        arr = new int[cap];
        front = rear = -1;
    }

    bool isfull()
    {
        return rear == cap - 1;
    }

    bool isempty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(int d)
    {
        if (isfull())
        {
            cout << "Queue Full" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        cout << "Enqueued: " << d << endl;
        arr[++rear] = d;
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << "Queue Already Empty" << endl;
            return -1;
        }
        int v = arr[front++];
        cout << "Dequeued: " << v << endl;
        return v;
    }

    ~queue() { delete[] arr; }
};

int main()
{
    queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}