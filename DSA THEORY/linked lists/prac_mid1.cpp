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
        data = d;
        next = NULL;
    }
};

class linkedlist
{
public:
    node *head;
    node *tail;

    linkedlist()
    {
        head = tail = NULL;
    }

    void pushfront(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void pushback(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    void popfront()
    {
        if (head == NULL)
        {
            return;
        }

        node *temp = head;
        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void popback()
    {
        if (tail == NULL)
            return;

        node *temp = tail;
        tail = tail->prev;

        if (tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }

        delete temp;
    }

    void pushmiddle(int data, int pos)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = new_node;
        }
        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        new_node->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = new_node;
        }
        else
        {
            tail = new_node;
        }
        temp->next = new_node;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        node *curr = head;
        node *temp = NULL;

        tail = head;

        while (curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
        }
    }

    void addtomaster(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertion()
    {
        node *sorted = NULL;
        node *curr = head;
        node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            if (sorted == NULL || curr->data < sorted->data)
            {
                curr->next = sorted->next;
                sorted = curr;
            }
            else
            {
                node *temp = sorted;
                while (temp != NULL && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
    }

    void insertion()
    {
        node *curr = head;
        node *sorted = NULL;
        node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            if (sorted == NULL || curr->data < sorted->data)
            {
                curr->next = sorted;
                sorted = curr;
            }
            else
            {
                node *temp = sorted;
                while (temp != NULL && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
    }

    void merge(linkedlist &l1, linkedlist &l2)
    {
        node *p1 = l1.head;
        node *p2 = l2.head;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data < p2->data)
            {
                addtomaster(p1->data);
                p1 = p1->next;
            }
            else
            {
                addtomaster(p2->data);
                p2 = p2->next;
            }
        }

        while (p1 != NULL)
        {
            addtomaster(p1->data);
            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            addtomaster(p2->data);
            p2 = p2->next;
        }
    }
};

int main()
{
    linkedlist l1;
    linkedlist l2;
    linkedlist master;

    master.merge(l1, l2);
}