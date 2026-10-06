#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    int data;

    node(int d)
    {
        next = prev = NULL;
        data = d;
    }
};

class doubly
{
public:
    node *head;
    node *tail;

    doubly()
    {
        head = tail = NULL;
    }

    void add_back(int d)
    {
        node *newnode = new node(d);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }

        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }

    void add_two_lists(doubly &l2, doubly &result)
    {
        node *temp1 = head;
        node *temp2 = l2.head;
        while (temp1 != NULL && temp2 != NULL)
        {
            result.add_back(temp1->data + temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    void display()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    doubly list1;
    doubly list2;
    doubly result;

    list1.add_back(10);
    list1.add_back(20);
    list1.add_back(30);

    list2.add_back(5);
    list2.add_back(7);
    list2.add_back(9);

    list1.add_two_lists(list2, result);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    cout << "Result: ";
    result.display();

    return 0;
}
