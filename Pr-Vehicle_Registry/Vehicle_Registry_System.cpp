#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle(const string &id, const string &man, const string &mod, int yr)
        : vehicleID(id), manufacturer(man), model(mod), year(yr)
    {
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    string getVehicleID() const
    {
        return vehicleID;
    }

    virtual void display() const
    {
        cout << "                                                 -) ID: " << vehicleID << endl
             << "                                                 -) Manufacturer: " << manufacturer << endl
             << "                                                 -) Model: " << model << endl
             << "                                                 -) Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car(const string &id, const string &man, const string &mod, int yr, const string &fuel)
        : Vehicle(id, man, mod, yr), fuelType(fuel) {}

    void display() const override
    {
        Vehicle::display();
        cout << "                                                 -) Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
protected:
    string batteryCapacity;

public:
    ElectricCar(const string &id, const string &man, const string &mod, int yr, const string &fuel, string &battery)
        : Car(id, man, mod, yr, fuel), batteryCapacity(battery) {}

    void display() const override
    {
        Car::display();
        cout << "                                                 -) Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

class Aircraft
{
protected:
    string flightRange;

public:
    Aircraft(string range) : flightRange(range) {}

    virtual void display() const
    {
        cout << "                                                 -) Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(const string &id, const string &man, const string &mod, int yr, const string &fuel, string &range)
        : Car(id, man, mod, yr, fuel), Aircraft(range) {}

    void display() const override
    {
        Car::display();
        Aircraft::display();
    }
};

class SportsCar : public ElectricCar
{
protected:
    string topSpeed;

public:
    SportsCar(const string &id, const string &man, const string &mod, int yr, const string &fuel, string &battery, string &speed)
        : ElectricCar(id, man, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() const override
    {
        ElectricCar::display();
        cout << "                                                 -) Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(const string &id, const string &man, const string &mod, int yr, const string &fuel)
        : Car(id, man, mod, yr, fuel) {}

    void display() const override
    {
        cout << "                                                 -) Sedan: ";
        Car::display();
    }
};

class SUV : public Car
{
public:
    SUV(const string &id, const string &man, const string &mod, int yr, const string &fuel)
        : Car(id, man, mod, yr, fuel) {}

    void display() const override
    {
        cout << "                                                 -) SUV: ";
        Car::display();
    }
};

class VehicleRegistry
{
private:
    Vehicle **vehicles;
    int capacity;
    int count;

public:
    VehicleRegistry(int initialCapacity = 10) : capacity(initialCapacity), count(0)
    {
        vehicles = new Vehicle *[capacity];
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
        delete[] vehicles;
    }

    void addVehicle(Vehicle *vehicle)
    {
        if (count == capacity)
        {
            cout << "                                                +++ Record Entering Limit Reached +++ " << endl;
        }
        vehicles[count++] = vehicle;
    }

    void displayAllVehicles() const
    {
        for (int i = 0; i < count; i++)
        {
            cout << "                                         >>> Displaying Vehicle Record <<<" << endl;
            vehicles[i]->display();
        }
    }

    Vehicle *searchVehicleById(const string &id) const
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                return vehicles[i];
            }
        }
        return nullptr;
    }
};

