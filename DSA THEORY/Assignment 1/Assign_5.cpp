#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    int product_id;
    string product_name;
    string category;
    float price;

    node(int id, string name, string cat, float p)
    {
        product_id = id;
        product_name = name;
        category = cat;
        price = p;
        next = NULL;
    }
};

class linkedlist
{
private:
    node *head;
    node *tail;

public:
    linkedlist()
    {
        head = tail = NULL;
    }

    void insert(int id, string name, string cat, float price)
    {
        node *new_node = new node(id, name, cat, price);

        if (head == NULL || id < head->product_id)
        {
            new_node->next = head;
            head = new_node;
            return;
        }

        node *temp = head;
        while (temp->next != NULL && temp->next->product_id < id)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            cout << "Product ID: " << temp->product_id
                 << " | Name: " << temp->product_name
                 << " | Category: " << temp->category
                 << " | Price: " << temp->price << endl;
            temp = temp->next;
        }
    }

    void addToMaster(node *source)
    {
        node *new_node = new node(source->product_id, source->product_name, source->category, source->price);

        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void merge(linkedlist &l1, linkedlist &l2)
    {
        node *p1 = l1.head;
        node *p2 = l2.head;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->product_id < p2->product_id)
            {
                addToMaster(p1);
                p1 = p1->next;
            }

            else if (p2->product_id < p1->product_id)
            {
                addToMaster(p2);
                p2 = p2->next;
            }

            else
            {
                if (p1->price <= p2->price)
                {
                    addToMaster(p1);
                }
                else
                {
                    addToMaster(p2);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1 != NULL)
        {
            addToMaster(p1);
            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            addToMaster(p2);
            p2 = p2->next;
        }
    }
};

int main()
{
    linkedlist glowcare;
    linkedlist beautyhub;
    linkedlist master;

    glowcare.insert(10, "Face Wash", "Skincare", 250.0);
    glowcare.insert(20, "Lipstick", "Makeup", 500.0);
    glowcare.insert(40, "Shampoo", "Haircare", 800.0);
    glowcare.insert(60, "Perfume", "Fragrance", 1200.0);

    beautyhub.insert(20, "Lipstick", "Makeup", 450.0);
    beautyhub.insert(30, "Moisturizer", "Skincare", 300.0);
    beautyhub.insert(40, "Shampoo", "Haircare", 900.0);
    beautyhub.insert(50, "Sunscreen", "Skincare", 350.0);

    cout << "===== GlowCare Branch List =====" << endl;
    glowcare.display();

    cout << "\n===== BeautyHub Branch List =====" << endl;
    beautyhub.display();

    master.merge(glowcare, beautyhub);

    cout << "\n===== Master Product List (After Merge) =====" << endl;
    master.display();

    return 0;
}
