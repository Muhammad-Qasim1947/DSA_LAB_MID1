#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string data;
    node *next;

    node(string d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    bool isempty()
    {
        return top == NULL;
    }

    void visit(string d)
    {
        node *newnode = new node(d);

        newnode->next = top;
        top = newnode;

        cout << "Now At : " << d << endl;
    }

    string peek()
    {
        if (isempty())
        {
            return "No Previous Page In History";
        }

        return top->data;
    }

    string goBack()
    {
        if (isempty())
        {
            return "No Previous Page In History";
        }

        node *temp = top;
        string value = temp->data;

        top = top->next;

        delete temp;

        if (isempty())
        {
            cout << "No Previous Page In History" << endl;
        }
        else
        {
            cout << "Back To : " << peek() << endl;
        }
        return value;
    }
};

int main()
{
    stack s;

    s.visit("google.com");
    s.visit("github.com");
    s.visit("docs.com");

    cout << endl;

    s.goBack();
    s.goBack();
    s.goBack();
}