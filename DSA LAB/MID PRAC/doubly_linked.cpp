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

    void add_front(int d)
    {
        node *newnode = new node(d);
        if (head == NULL)
        {
            head = tail = newnode;
            return;
        }

        newnode->next = head;
        head->prev = newnode;
        head = newnode;
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

    void add_at_pos(int d, int pos)
    {
        node *temp = head;
        if (pos < 0)
        {
            cout << "Error" << endl;
            return;
        }
        if (pos == 0 || head == NULL)
        {
            add_front(d);
            return;
        }

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *newnode = new node(d);
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "NOTHING TO POP" << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = NULL;
        }
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "NOTHING TO POP" << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = NULL;
        }
        node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
    }

    void pop_at_pos(int pos)
    {
        if (head == NULL || pos < 0)
        {
            cout << "NOTHING TO POP" << endl;
            return;
        }

        if (pos == 0 || head == NULL)
        {
            pop_front();
            return;
        }

        node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node *del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;

        delete del;
    }

    void insertion_sort()
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
                while (temp->next != NULL && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }

        head = sorted;
        node *p = NULL;
        node *c = head;
        while (c != NULL)
        {
            c->prev = p;
            p = c;
            c = c->next;
        }
        tail = p;
    }

    int search(int key)
    {
        node *temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return index;
            }

            temp = temp->next;
            index++;
        }
        return -1;
    }

    void reverse()
    {
        node *curr = head;
        node *temp = NULL;

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

    int sum(){
        node *temp = head ;
        int total = 0 ;
        while (temp != NULL)
        {
            total += temp->data ;
            temp = temp->next ;
        }
        return total ;
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

    cout << "--- add_front / add_back ---" << endl;
    list.add_front(10);
    list.add_front(5);
    list.add_back(20);
    list.add_back(30);
    list.display_forward();  // 5 <-> 10 <-> 20 <-> 30 <-> NULL
    list.display_backward(); // 30 <-> 20 <-> 10 <-> 5 <-> NULL
    cout << "Sum : " << list.sum() << endl ;

    cout << "--- add_at_pos(15, 2) ---" << endl;
    list.add_at_pos(15, 2);
    list.display_forward(); // 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> NULL

    cout << "--- search ---" << endl;
    cout << "search(20) = " << list.search(20) << endl; // 3
    cout << "search(99) = " << list.search(99) << endl; // -1

    cout << "--- pop_front ---" << endl;
    list.pop_front();
    list.display_forward(); // 10 <-> 15 <-> 20 <-> 30 <-> NULL

    cout << "--- pop_back ---" << endl;
    list.pop_back();
    list.display_forward(); // 10 <-> 15 <-> 20 <-> NULL

    cout << "--- pop_at_pos(1) ---" << endl;
    list.pop_at_pos(1);
    list.display_forward(); // 10 <-> 20 <-> NULL

    cout << "--- reverse ---" << endl;
    list.add_back(40);
    list.add_back(50);
    list.display_forward(); // 10 <-> 20 <-> 40 <-> 50 <-> NULL
    list.reverse();
    list.display_forward();  // 50 <-> 40 <-> 20 <-> 10 <-> NULL
    list.display_backward(); // 10 <-> 20 <-> 40 <-> 50 <-> NULL

    cout << endl ;
    cout << "Insertion Sorting" << endl ;

    doubly sort ;
    sort.add_front(10);
    sort.add_front(5);
    sort.add_front(2);
    sort.add_front(9);
    sort.add_front(20);
    sort.add_front(78);

    sort.display_forward();
    sort.insertion_sort();
    sort.display_forward();
    return 0;
}
