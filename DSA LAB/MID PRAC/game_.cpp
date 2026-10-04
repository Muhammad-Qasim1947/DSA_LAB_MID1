#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string name;
    node *next;

    node(string n)
    {
        name = n;
        next = NULL;
    }
};

class turnManager
{
private:
    node *head;
    node *tail;
    node *current;

public:
    turnManager()
    {
        head = tail = current = NULL;
    }

    void addPlayer(string name)
    {
        node *newnode = new node(name);

        if (head == NULL)
        {
            head = tail = current = newnode;
            tail->next = head;
            return;
        }

        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }

    void nextturn()
    {
        if (current == NULL)
        {
            cout << "No Players Left" << endl;
            return;
        }

        current = current->next;
        cout << "Player : " << current->name << endl;
    }

    void removeplayer(string name)
    {
        if (head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        node *prev = tail; // head ka prev tail hota hai
        node *curr = head;
        do
        {
            if (curr->name == name)
            {
                break;
                ;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->name != name)
        {
            cout << name << " not found" << endl;
            return;
        }

        if (curr == head && curr == tail)
        {
            head = tail = current = NULL;
            delete curr;
            return;
        }
        if (curr == head)
            head = curr->next;
        if (curr == tail)
            tail = prev;
        if (curr == current)
            current = prev;

        delete curr;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "No players" << endl;
            return;
        }

        node *temp = head;
        do
        {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->name << ")" << endl;
    }
};

int main()
{
    turnManager game;
    game.addPlayer("Ali");
    game.addPlayer("Beena");
    game.addPlayer("Cara");
    game.display();
    return 0;
}