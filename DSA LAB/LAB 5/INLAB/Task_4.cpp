#include <iostream>
using namespace std;

class queue
{
private:
    string *arr;
    int front, rear;
    int cap;

public:
    queue(int c)
    {
        cap = c;
        arr = new string[cap];
        front = rear = -1;
    }

    bool isempty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        return false;
    }

    bool isfull()
    {
        return (rear + 1) % cap == front;
    }

    void enqueue(string name)
    {
        if (isfull())
        {
            cout << "Queue is full, cannot add " << name << endl;
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

        arr[rear] = name;

        cout << name << " added to queue" << endl;
    }

    string dequeue()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return "";
        }

        string value = arr[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % cap;
        }

        cout << "Serving " << value << endl;

        return value;
    }

    void displayqueue()
    {
        if (isempty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;

        while (true)
        {
            cout << arr[i] << endl;

            if (i == rear)
                break;

            i = (i + 1) % cap;
        }
    }
};

int main()
{
    int c;
    string cus;
    queue q(3);

    do
    {
        cout << "1. ADD CUSTOMER  2. SERVER CUSTOMER  3. VIEW QUEUE  4. EXIT" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Add Customer : ";
            cin >> cus;
            q.enqueue(cus);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.displayqueue();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            break;
        }
    } while (c != 4);
}