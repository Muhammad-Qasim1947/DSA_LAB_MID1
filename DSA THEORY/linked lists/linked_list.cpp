#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
public:
    node *head;
    node *tail;

public:
    list()
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
            head = new_node;
        }
    }

    void push_back(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = tail = new_node;
            return;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Error" << endl;
            return;
        }

        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
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

    void insert(int val, int pos)
    {
        node *temp = head;

        if (pos < 0)
        {
            cout << "Error" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node *new_node = new node(val);
        new_node->next = temp->next;
        temp->next = new_node;
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

    void addtomaster(int data)
    {
        node *new_node = new node(data);

        if (head == NULL)
        {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        tail = new_node;
    }

    void merge(list &l1, list &l2)
    {
        node *p1 = head;
        node *p2 = head;

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

    // list split()
    // {
    //     list l1;

    //     if (head == NULL || head->next == NULL)
    //     {
    //         return;
    //     }

    //     node *slow = l1.head;
    //     node *fast = l1.head;

    //     while (fast != NULL || fast->next != NULL)
    //     {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }

    //     l1.head = slow->next;
    //     slow->next = NULL;

    //     return l1;
    // }

    void insertion_sort()
    {
        node *sorted = NULL;
        node *curr = head;
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

    void reverse()
    {
        tail = head;

        node *curr = head;
        node *prev = NULL;
        node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
void delete_by_pos(list &l1, list &l2)
{

    node *temp2 = l2.head;

    while (temp2 != NULL)
    {
        node *temp1 = l1.head;
        int count = 0;
        int pos = temp2->data;
        node *prev = NULL;

        while (temp1 != NULL && count < pos)
        {
            prev = temp1;
            temp1 = temp1->next;
            count++;
        }
        if (temp1 == NULL)
        {
            temp2 = temp2->next;
            continue;
        }
        if (prev == NULL)
        {

            l1.head = temp1->next;
        }
        else
        {
            prev->next = temp1->next;
            temp1->next = NULL;
        }

        delete temp1;
        temp2 = temp2->next;
    }
}
int main()
{
    // list ll;

    // cout << endl;
    // ll.push_front(1);
    // ll.push_front(2);
    // ll.push_front(3);
    // ll.display(); // 3 -> 2 -> 1 -> NULL

    // cout << endl;

    // ll.push_back(4);
    // ll.display(); // 3 -> 2 -> 1 -> 4 -> NULL

    // cout << endl;

    // ll.pop_front();
    // ll.display(); // 2 -> 1 -> 4 -> NULL

    // cout << endl;

    // ll.pop_back();
    // ll.display(); // 2 -> 1 -> NULL

    // cout << endl;

    // ll.insert(4, 1); // me yaha 1 likhuga to new node hamara 0 index ke bad yani 1 index per ayega
    // ll.display();    // 2 -> 4 -> 1 -> NULL

    // cout << endl;

    // cout << "Index  = " << ll.search(2) << endl;
    list l1;
    // list l2;
    // list master;

    // master.merge(l1, l2);

    l1.push_front(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(4);
    l1.push_back(6);
    l1.push_back(3);
    list l2;
    l2.push_back(1);
    l2.push_back(3);
    l1.display();
    delete_by_pos(l1, l2);

    l1.display();
}