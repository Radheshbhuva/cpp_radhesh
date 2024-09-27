#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string address;

public:
    Person() : name(""), age(0), address("") {}

    Person(const string &n, int a, const string &addr)
        : name(n), age(a), address(addr) {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    string getAddress() const
    {
        return address;
    }
};
