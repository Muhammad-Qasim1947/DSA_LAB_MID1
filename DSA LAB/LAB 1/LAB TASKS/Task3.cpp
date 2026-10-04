#include <iostream>
using namespace std;

class Rectangle
{
private:
    int *width;
    int *height;

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

    int *getWidth() const
    {
        return width;
    }

    int *getHeight() const
    {
        return height;
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
    Rectangle r1(4, 5);

    // Default copy constructor
    Rectangle r2 = r1;

    cout << "Address of r1 width: " << r1.getWidth() << endl;
    cout << "Address of r2 width: " << r2.getWidth() << endl;

    cout << endl;

    *r2.getWidth() = 10;

    cout << "After modifying r2 width:" << endl;
    r1.display();

    return 0;
}