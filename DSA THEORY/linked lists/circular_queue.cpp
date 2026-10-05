#include <iostream>
using namespace std;

class queue
{
private:
    int rear;
    int front;
    int *arr;
    int size;

public:
    queue(int s) : rear(-1), front(-1)
    {
        size = s;
        arr = new int[s];
    }

    bool is_empty()
    {
        if (rear == -1)
        {
            return true;
        }
        return false;
    }

    bool is_full()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        if (is_full())
        {
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
    int dequeue()
    {
        if (is_empty())
        {
            return -1;
        }
        return arr[front++];
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    queue  q(3);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(5);
    q.print();

}