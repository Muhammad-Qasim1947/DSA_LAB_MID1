#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    char move;
    int prevpos;
    node *next;

    node(char m, int pos)
    {
        move = m;
        prevpos = pos;
        next = NULL;
    }
}; 

class stack
{
    node *top;
    int count;

public:
    stack() : top(NULL), count(0) {}

    bool isEmpty() const
    {
        return top == nullptr;
    }

    int size() const
    {
        return count;
    }

    node *get_top()
    {
        return top;
    }

    void push(int m, int pos)
    {
        node *newnode = new node(m, pos);

        newnode->next = top;
        top = newnode;
        count++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        node *temp = top;
        top = temp->next;
        temp->next = NULL;
        delete temp;
        count--;
    }

    void display_toptobot()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        node *temp = top;
        while (temp->next != NULL)
        {
            cout << "[" << temp->move << ", posBefore=" << temp->prevpos << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter The Number Of Commands : " << endl;
    cin >> n;

    stack s;
    int position = 0;
    int successfulMoves = 0;
    int successfulUndos = 0;

    cout << "Enter " << n << " commands (R, L, J, B), space or newline separated:\n";

    for (int i = 0; i < n; i++)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'R' || cmd == 'r')
        {
            int newpos = position + 1;
            if (newpos >= 0)
            {
                s.push('R', position);
                position = newpos;
                successfulMoves++;
            }
        }

        else if (cmd == 'L' || cmd == 'l')
        {
            int newPos = position - 1;
            if (newPos >= 0)
            {
                s.push('L', position);
                position = newPos;
                successfulMoves++;
            }
        }

        else if (cmd == 'J' || cmd == 'j')
        {
            int newpos = position + 2;
            if (newpos >= 0)
            {
                s.push('J', position);
                position = newpos;
                successfulMoves++;
            }
        }

        else if (cmd == 'B' || cmd == 'b')
        {
            if (!s.isEmpty())
            {
                position = s.get_top()->prevpos;
                s.pop();
                successfulUndos++;
            }
            else
            {
                cout << "Nothing to undo! Stack is empty.\n";
            }
        }
    }

    cout << "\n================ Final State ================\n";
    cout << "Final Position: " << position << endl;
    cout << "Successful Moves: " << successfulMoves << endl;
    cout << "Successful Undos: " << successfulUndos << endl;
    cout << "Remaining Elements in Stack: ";
    s.display_toptobot();

    return 0 ;
}