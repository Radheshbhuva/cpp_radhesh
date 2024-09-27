#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    void display() const
    {
        std::cout << real << " + " << imag << "j" << std::endl;
    }
};

int main()
{

    double real1, imag1, real2, imag2;

    std::cout << "Enter the real and imaginary parts of the first complex number (e.g., 4 7): ";
    std::cin >> real1 >> imag1;
    Complex c1(real1, imag1);

    std::cout << "Enter the real and imaginary parts of the second complex number (e.g., 2 3): ";
    std::cin >> real2 >> imag2;
    Complex c2(real2, imag2);

    Complex result = c1 - c2;

    std::cout << "Result of subtraction: ";
    result.display();

    return 0;
}
