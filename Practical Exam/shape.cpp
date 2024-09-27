#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    void draw() const override
    {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override
    {
        return width * height;
    }

    void draw() const override
    {
        cout << "Drawing a Rectangle with width " << width << " and height " << height << endl;
    }
};

int main()
{

    Shape *shapes[2];

    double radius;
    cout << "Enter the radius of the Circle: \n";
    cin >> radius;
    shapes[0] = new Circle(radius);

    double width, height;
    cout << "Enter the width and height of the Rectangle: \n";
    cin >> width >> height;
    shapes[1] = new Rectangle(width, height);

    for (int i = 0; i < 2; ++i)
    {
        cout << "Area: " << shapes[i]->area() << endl;
        shapes[i]->draw();
    }
    return 0;
}
