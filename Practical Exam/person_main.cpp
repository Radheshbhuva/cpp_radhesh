#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

int main()
{
    const int maxPersons = 100;
    Person persons[maxPersons];
    int numberOfPersons;

    cout << "Enter the number of persons ";
    cin >> numberOfPersons;
    cin.ignore();

    if (numberOfPersons > maxPersons)
    {
        cout << "Number of persons exceeds the maximum limit. Setting to " << maxPersons << ".\n";
        numberOfPersons = maxPersons;
    }

    for (int i = 0; i < numberOfPersons; i++)
    {
        string name;
        int age;
        string address;

        cout << "Enter details for person " << (i + 1) << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        cout << "Address: ";
        getline(cin, address);

        persons[i] = Person(name, age, address);
    }

    cout << "\nYou entered the following persons:\n";
    for (int i = 0; i < numberOfPersons; i++)
    {
        cout << "Name: " << persons[i].getName()
             << ", Age: " << persons[i].getAge()
             << ", Address: " << persons[i].getAddress() << endl;
    }

    return 0;
}
