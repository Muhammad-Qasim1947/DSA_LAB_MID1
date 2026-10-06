// Buffer class doesnt define its own copy constructor so the compiler automatically 
// generates a default one and that default version only performs a shallow copy. This means 
// when b2 is copied from b1, only the data pointer itself gets copied, not the actual memory
// it points to .... As a result, both b1 and b2 end up pointing to the exact same block of heap

// This corruption is not found at the end of the program when destructors run. 
// It is actually visible earlier, during normal execution. The reason is that
// b1 and b2 never had copies of the data. They both point to the underlying memory 
// all the time. So when we change b2[1] and set it to 20 that change does not stay in b2. 
// It also appears in b1 because both objects are really just looking at the memory location. 
// The consequence is that b1[1], which should still be 0 now also shows 20 even though b1 
// was never directly changed.

#include <iostream>
using namespace std;

class Buffer
{
private:
    int* data;
    int length;

public:

    Buffer(int len)
    {
        length = len;
        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = 0;
        }
    }

    Buffer(const Buffer& other)
    {
        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }

    Buffer& operator=(const Buffer& other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    void setValue(int index, int value)
    {
        data[index] = value;
    }

    void display() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    ~Buffer()
    {
        delete[] data;
    }
};

int main()
{
    Buffer b1(5);

    b1.setValue(0, 10);

    Buffer b2 = b1;

    b2.setValue(1, 20);

    b1.display();
    b2.display();

    return 0;
}