#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int top;
    int cap;

public:
    stack()
    {
        arr = NULL;
        cap = 0;
        top = -1;
    }

    stack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    bool isempty()
    {
        return top == -1;
    }

    bool isfull()
    {
        return top == cap - 1;
    }

    void push(int d)
    {
        if (isfull())
        {
            cout << "Stack Full" << endl;
            return;
        }
        arr[++top] = d;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isempty())
        {
            return -1;
        }
        return arr[top];
    }

    void removeelement(int e)
    {
        stack temp(cap);
        while (!isempty())
        {
            int val = pop();
            if (val != e)
            {
                temp.push(val);
            }
        }
        while (!temp.isempty())
        {
            push(temp.pop());
        }
    }

    bool contain(int x)
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }

    void remove_dups()
    {
        stack temp(cap);
        while (!isempty())
        {
            int x = pop();
            if (!temp.contain(x))
            {
                temp.push(x);
            }
        }
        while (!temp.isempty())
        {
            push(temp.pop());
        }
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    stack merge(stack s1, stack s2)
    {
        stack result(s1.top + s2.top + 2);
        while (!s1.isempty() && !s2.isempty())
        {
            if (s1.peek() < s2.peek())
            {
                result.push(s1.pop());
            }
            else
            {
                result.push(s2.pop());
            }
        }

        while (!s1.isempty())
        {
            result.push(s1.pop());
        }
        while (!s2.isempty())
        {
            result.push(s2.pop());
        }
        return result;
    }

    void sort()
    {
        stack temp(cap);
        while (!isempty())
        {
            int t = pop();
            while (!temp.isempty() && temp.peek() < t)
            {
                push(temp.pop());
            }
            temp.push(t);
        }
        while (!temp.isempty())
        {
            push(temp.pop());
        }
    }
};

int main()
{
    stack s(10);
    s.push(10);
    s.push(20);
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(40);

    cout << "Original (top first): ";
    s.display();

    cout << "peek: " << s.peek() << endl;
    cout << "contain(30): " << s.contain(30) << endl;

    s.removeelement(30);
    cout << "After removeelement(30): ";
    s.display();

    s.remove_dups();
    cout << "After remove_dups: ";
    s.display();

    s.sort();
    cout << "After Sorting : " ;
    s.display();

    stack a(5), b(5);
    a.push(9);
    a.push(5);
    a.push(1);
    b.push(8);
    b.push(6);
    b.push(2);

    stack m = s.merge(a, b);
    cout << "Merged (top first): ";
    m.display();


}