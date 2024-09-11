#include <iostream>
#include <string>
#include "Vehicle_Registry_System.cpp"
using namespace std;  


int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout << endl
             << endl
             << "-----------------------" << endl;
        cout << "Vehicle Registry System" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string id, man, mod, fuel, battery, range, speed;
        int year;

        switch (choice)
        {
        case 1:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> man;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> year;

            cout << "1. Car" << endl
                 << "2. Electric Car" << endl
                 << "3. Flying Car" << endl
                 << "4. Sports Car" << endl
                 << "5. Sedan" << endl
                 << "6. SUV" << endl
                 << "7. Aircraft" << endl
                 << "Select Vehicle Type: " << endl;
            int type;
            cin >> type;

            switch (type)
            {
            case 1:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Car(id, man, mod, year, fuel));
                break;
            case 2:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                registry.addVehicle(new ElectricCar(id, man, mod, year, fuel, battery));
                break;
            case 3:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Flight Range (km): ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));
                break;
            case 4:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                cout << "Enter Top Speed (km/h): ";
                cin >> speed;
                registry.addVehicle(new SportsCar(id, man, mod, year, fuel, battery, speed));
                break;
            case 5:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Sedan(id, man, mod, year, fuel));
                break;
            case 6:
                cout << "Enter Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new SUV(id, man, mod, year, fuel));
                break;
            case 7:

                cout << "Enter flightrange: ";
                cin >> range;
                registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));

            default:
                cout << "Invalid vehicle type selected." << endl;
            }
            break;
        case 2:
            registry.displayAllVehicles();
            break;
        case 3:
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            if (Vehicle *vehicle = registry.searchVehicleById(id))
            {
                vehicle->display();
            }
            else
            {
                cout << "Vehicle not found." << endl;
            }
            break;
        case 4:
            cout << "Exiting the Registry System" << endl;
            break;
        default:
            cout << "Invalid choice, Please try again :( )" << endl;
        }
    } while (choice != 4);

    return 0;
}
