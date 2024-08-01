#include <iostream>

class MyClass
{
private:
    int pvt;  // pvt = Private

public:
    int pbc; // pbc = Public

    MyClass()
    {
        pvt = 100;
        pbc = 200;
    }

 
    void printPrivate2()
    {
        std::cout << "Private Variable: " << pvt << std::endl;
    }

    void setPrivate2(int value)
    {
        pvt = value;
    }
};

int main()
{
    MyClass obj;

   
    std::cout << "Public Variable: " << obj.pbc<< std::endl;

   
    obj.printPrivate2();

    
    obj.setPrivate2(300);
    obj.printPrivate2();
    return 0;
}