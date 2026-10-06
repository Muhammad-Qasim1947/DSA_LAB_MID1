#include <iostream>
using namespace std;

class DynamicString
{
private:
    char* data;

public:

    DynamicString(const char* text)
    {
        int len = 0;

        while (text[len] != '\0')
        {
            len++;
        }

        data = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            data[i] = text[i];
        }
    }

    DynamicString()
    {
        data = new char[1];
        data[0] = '\0';
    }

    DynamicString(const DynamicString& other)
    {
        int len = 0;

        while (other.data[len] != '\0')
        {
            len++;
        }

        data = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            data[i] = other.data[i];
        }
    }

    DynamicString& operator=(const DynamicString& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        int len = 0;

        while (other.data[len] != '\0')
        {
            len++;
        }

        data = new char[len + 1];

        for (int i = 0; i <= len; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    ~DynamicString()
    {
        delete[] data;
    }

    int length() const
    {
        int len = 0;

        while (data[len] != '\0')
        {
            len++;
        }

        return len;
    }

    void print() const
    {
        cout << data << endl;
    }

    void setChar(int index, char c)
    {
        if (index >= 0 && index < length())
        {
            data[index] = c;
        }
    }
};

int main()
{
    DynamicString s1("Hello");

    DynamicString s2 = s1;

    DynamicString s3;
    s3 = s1;

    cout << "Before changing s2:" << endl;

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    cout << "s3: ";
    s3.print();

    s2.setChar(0, 'Y');

    cout << "\nAfter changing s2:" << endl;

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    cout << "s3: ";
    s3.print();

    cout << "\nLength of s1: " << s1.length() << endl;

    return 0;
}