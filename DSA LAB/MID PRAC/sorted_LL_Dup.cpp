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
private:
    node *head;
    node *tail;

public:
    doubly()
    {
        head = tail = NULL;
    }

    void insert_sorted(int d)
    {
        node *newnode = new node(d);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }

        if (d <= head->data)
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }

        if (d >= tail->data)
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            return;
        }

        node *temp = head;
        while (temp != NULL && temp->next->data < d)
        {
            temp = temp->next;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }

    void delete_dup()
    {
        node *temp = head;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                node *del = temp->next;
                if (del->next != NULL)
                {
                    temp->next = del->next;
                    del->next->prev = temp;
                    delete del;
                }
                else
                {
                    temp->next = NULL;
                    tail = temp;
                    delete del;
                }
            }
            temp = temp->next;
        }
    }

    int middle()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return -1;
        }

        node *slow = head;
        node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }

    void addtomaster(node *source)
    {
        node *newnode = new node(source->data);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void merge(doubly &l1, doubly &l2)
    {
        node *p1 = l1.head;
        node *p2 = l2.head;
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                addtomaster(p1);
                p1 = p1->next;
            }

            else if (p2->data < p1->data)
            {
                addtomaster(p2);
                p2 = p2->next;
            }
            else
            {
                addtomaster(p1);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            addtomaster(p1);
            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            addtomaster(p2);
            p2 = p2->next;
        }
    }

    void display_forward()
    {
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void display_backward()
    {
        node *temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    doubly list;
    list.insert_sorted(30);
    list.insert_sorted(10);
    list.insert_sorted(20);
    list.insert_sorted(20);
    list.insert_sorted(5);
    list.insert_sorted(25);
    list.display_forward();  // 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> NULL
    list.display_backward(); // 30 <-> 25 <-> 20 <-> 10 <-> 5 <-> NULL
    cout << "After Duplicate Deletion : " << endl;
    list.delete_dup();
    list.display_forward(); // 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> NULL

    // for merging two linked list :
    doubly l1;
    doubly l2;
    doubly master;
    l1.insert_sorted(30);
    l1.insert_sorted(10);
    l1.insert_sorted(20);
    l2.insert_sorted(5);
    l2.insert_sorted(45);
    l2.insert_sorted(10);
    master.merge(l1, l2);
    master.display_forward();
}