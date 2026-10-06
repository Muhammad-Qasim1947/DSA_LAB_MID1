#include <iostream>
using namespace std;

class Rectangle
{
private:
    int* width;
    int* height;

public:
    Rectangle(int w, int h)
    {
        width = new int;
        height = new int;

        *width = w;
        *height = h;
    }

    int area() const
    {
        return (*width) * (*height);
    }

    void display() const
    {
        cout << "Width: " << *width << endl;
        cout << "Height: " << *height << endl;
        cout << "Area: " << area() << endl;
    }

    ~Rectangle()
    {
        delete width;
        delete height;

        cout << "Rectangle destroyed" << endl;
    }
};

int main()
{
    Rectangle r(10, 5);

    r.display();

    return 0;
}