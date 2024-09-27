#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    string name;
    string sound;

public:
    void setName(const string &animalName)
    {
        name = animalName;
    }

    void setSound(const string &animalSound)
    {
        sound = animalSound;
    }

    string getName() const
    {
        return name;
    }

    string getSound() const
    {
        return sound;
    }

    virtual void displayDetails() const
    {
        cout << "Animal Name: " << getName() << endl;
        cout << "Animal Sound: " << getSound() << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(const string &name)
    {
        setName(name);
        setSound("Bark");
    }

    void makeSound() const
    {
        cout << getSound() << endl;
    }

    void displayDetails() const override
    {
        Animal::displayDetails();
        cout << "This dog says: ";
        makeSound();
    }
};

class Cat : public Animal
{
public:
    Cat(const string &name)
    {
        setName(name);
        setSound("Meow");
    }

    void makeSound() const
    {
        cout << getSound() << endl;
    }

    void displayDetails() const override
    {
        Animal::displayDetails();
        cout << "This cat says: ";
        makeSound();
    }
};

int main()
{
    string dogName, catName;

    cout << "Enter the name of the dog: ";
    getline(cin, dogName);
    Dog dog(dogName);

    cout << "Enter the name of the cat: ";
    getline(cin, catName);
    Cat cat(catName);

    cout << "\nDog Details:" << endl;
    dog.displayDetails();

    cout << "\nCat Details:" << endl;
    cat.displayDetails();

    return 0;
}
