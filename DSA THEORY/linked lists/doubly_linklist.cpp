#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class doublylist
{
    node *head;
    node *tail;

public:
    doublylist()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = tail = new_node;
            return;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void push_back(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = tail = NULL;
            return;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_front()
    {

        node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            temp->next = NULL;
            head->prev = NULL;
            delete temp;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Error" << endl;
            return;
        }

        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;

        delete tail;
        tail = temp;
    }

    void reverse()
    {
        node *temp = NULL;
        node *curr = head;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};

main()
{
    doublylist ll;

    cout << endl;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.display(); // 3 -> 2 -> 1 -> NULL

    cout << endl;

    ll.push_back(4);
    ll.display(); // 3 -> 2 -> 1 -> 4 -> NULL

    cout << endl;

    ll.pop_front();
    ll.display(); // 2 -> 1 -> 4 -> NULL
}