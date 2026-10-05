#include <iostream>
using namespace std;

class node
{
public:
    node *next;

    int rider_id;
    string rider_name;
    int assigned_orders;

    node(int id, string name, int orders)
    {
        rider_id = id;
        rider_name = name;
        assigned_orders = orders;
        next = NULL;
    }
};

class circular
{
public:
    node *head;
    node *tail;

    circular()
    {
        head = tail = NULL;
    }

    void add_rider_beginning(int id, string name, int orders)
    {
        node *new_rider = new node(id, name, orders);

        if (head == NULL)
        {
            head = tail = new_rider;
            tail->next = head;
        }
        else
        {
            new_rider->next = head;
            head = new_rider;
            tail->next = head;
        }
        cout << "Rider " << name << " (ID: " << id << ") added successfully.\n";
    }

    void add_rider_ending(int id, string name, int orders)
    {
        node *new_rider = new node(id, name, orders);

        if (head == NULL)
        {
            head = tail = new_rider;
            tail->next = head;
        }
        else
        {
            tail->next = new_rider;
            new_rider->next = head;
            tail = new_rider;
        }
    }

    void add_rider_specific(int id, string name, int orders, int pos)
    {
        node *temp = head;

        if (pos < 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 0)
        {
            add_rider_beginning(id, name, orders);
            return;
        }

        if (head == NULL)
        {
            cout << "List is empty, position out of bounds!" << endl;
            return;
        }

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node *new_rider = new node(id, name, orders);

        new_rider->next = temp->next;
        temp->next = new_rider;

        if (temp == tail)
        {
            tail = new_rider;
        }
    }

    void del_from_beginning()
    {
        if (head == NULL)
            return;

        node *temp = head;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        delete temp;
    }

    void del_from_ending()
    {
        if (head == NULL)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = head;
    }

    void del_from_specific_pos(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 0)
        {
            del_from_beginning();
            return;
        }

        node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node *to_delete = temp->next;
        temp->next = to_delete->next;

        if (to_delete == tail)
        {
            tail = temp;
        }

        delete to_delete;
    }

    bool find_rider(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return false;
        }

        node *temp = head;

        do
        {
            if (temp->rider_id == id)
            {
                cout << "Rider Found With ID : " << id << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Not Found" << endl;
        return false;
    }

    bool update_rider(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return false;
        }

        node *temp = head;

        do
        {
            if (temp->rider_id == id)
            {
                cout << "Rider Found! Enter New Details:" << endl;

                cout << "Enter New Name: ";
                cin >> temp->rider_name;

                cout << "Enter New Assigned Orders: ";
                cin >> temp->assigned_orders;

                cout << "Rider information updated successfully" << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Rider with ID " << id << " not found!" << endl;
        return false;
    }

    void display_all_riders()
    {
        if (head == NULL)
        {
            cout << "List is empty! No riders to display." << endl;
            return;
        }

        node *temp = head;
        cout << "\n--- Rider List ---" << endl;

        do
        {
            cout << "ID: " << temp->rider_id << " | Name: " << temp->rider_name << endl;
            temp = temp->next;

        } while (temp != head); // Wapas head par aane tak chalega

        cout << "------------------" << endl;
    }

    int count_riders()
    {
        if (head == NULL)
        {
            return 0;
        }

        int count = 0;
        node *temp = head;

        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void display_from_rider(int start_id)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *start_node = head;
        bool found = false;

        do
        {
            if (start_node->rider_id == start_id)
            {
                found = true;
                break;
            }
            start_node = start_node->next;
        } while (start_node != head);

        if (!found)
        {
            cout << "Rider with ID " << start_id << " not found!" << endl;
            return;
        }

        node *temp = start_node;
        cout << "\n--- Displaying Riders Starting From ID: " << start_id << " ---" << endl;

        do
        {
            cout << "ID: " << temp->rider_id << " | Name: " << temp->rider_name << endl;
            temp = temp->next;
        } while (temp != start_node);
        cout << "-----------------------------------------------" << endl;
    }
};

int main()
{
    circular list;

    // Adding riders
    list.add_rider_ending(101, "Ali", 5);
    list.add_rider_ending(102, "Bilal", 3);
    list.add_rider_ending(103, "Sara", 7);
    list.add_rider_beginning(100, "Zain", 2);
    list.add_rider_specific(104, "Hina", 4, 2);

    // Display all
    list.display_all_riders();

    // Count
    cout << "Total Riders: " << list.count_riders() << endl;

    // Find
    list.find_rider(102);

    // Display starting from a specific rider
    list.display_from_rider(102);

    // Delete operations
    list.del_from_beginning();
    list.del_from_ending();
    list.del_from_specific_pos(1);

    // Display after deletions
    list.display_all_riders();

    cout << "Total Riders: " << list.count_riders() << endl;

    return 0;
}