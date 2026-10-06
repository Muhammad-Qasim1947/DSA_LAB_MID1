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

    void delete_val(int key)
    {
        if (head == NULL)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (head->data == key)
        {
            node *del = head;
            if (head == tail)
            {
                head = tail = NULL;
                delete del;
                return;
            }
            else
            {
                head = head->next;
                tail->next = head;
                del->next = NULL;
                delete del;
                return;
            }
        }

        node *temp = head;
        do
        {
            if (temp->next->data == key)
            {
                if (temp->next == tail)
                {
                    node *del = temp->next;
                    tail = temp;
                    tail->next = head;
                    del->next = NULL;
                    delete del;
                    return;
                }
                else
                {
                    node *del = temp->next;
                    temp->next = del->next;
                    del->next = NULL;
                    delete del;
                    return;
                }
            }
            temp = temp->next;
        } while (temp != head);
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

    void reverse()
    {
        if (head == NULL || head == tail)
        {
            return;
        }

        node *prev = tail;
        node *curr = head;
        node *next = NULL;

        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);
        
        node *temp = head;
        head = tail;
        tail = temp;
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
};

int main()
{
    circular c;

    cout << "===== PUSH FRONT =====" << endl;
    c.pushfront(30);
    c.pushfront(20);
    c.pushfront(10);

    c.display();

    cout << "\n===== APPEND =====" << endl;
    c.append(40);
    c.append(50);

    c.display();

    cout << "\n===== INSERT =====" << endl;
    c.insert(3, 35);
    c.insert(5, 45);

    c.display();

    cout << "\n===== SEARCH =====" << endl;
    cout << "Search 35: ";

    if (c.search(35))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Search 100: ";

    if (c.search(100))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "\n===== DELETE MIDDLE =====" << endl;
    c.delete_val(35);
    c.display();

    cout << "\n===== DELETE HEAD =====" << endl;
    c.delete_val(10);
    c.display();

    cout << "\n===== DELETE TAIL =====" << endl;
    c.delete_val(50);
    c.display();

    cout << "\n===== REVERSE =====" << endl;
    c.reverse();
    c.display();

    cout << "\n===== INSERT AFTER REVERSE =====" << endl;
    c.pushfront(5);
    c.append(60);
    c.insert(2, 15);
    c.display();

    return 0;
}