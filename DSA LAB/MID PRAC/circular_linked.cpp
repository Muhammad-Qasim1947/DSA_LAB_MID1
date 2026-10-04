#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    int data;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class circular
{
public:
    node *head;
    node *tail;
    node *current;

    circular()
    {
        head = tail = NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Nothing To Display" << endl;
            return;
        }

        node *temp = head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void append(int val)
    {
        node *newnode = new node(val);

        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
            return;
        }
        tail->next = newnode;
        tail = newnode;
        newnode->next = head;
    }

    void pushfront(int val)
    {
        node *newnode = new node(val);

        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
            return;
        }
        tail->next = newnode;
        newnode->next = head;
        head = newnode;
    }

    void insert(int pos, int val)
    {
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 0 || head == NULL)
        {
            pushfront(val);
            return;
        }

        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node *newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail)
        {
            tail = newnode;
        }
    }

    void delete_val(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->data == val) // head hatana hai
        {
            node *del = head;
            if (head == tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->next;
                tail->next = head;
            }
            delete del;
            return;
        }
        node *prev = head;
        node *curr = head->next;

        while (curr != head)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                if (curr == tail)
                {
                    tail = prev;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Value not found" << endl;
    }

    bool search(int key)
    {
        if (head == NULL)
            return false;

        node *temp = head;
        do
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }
};

int main()
{
}