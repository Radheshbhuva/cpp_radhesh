#include <iostream>
#include <string>
using namespace std;

class Record
{
private:
    int trainnumber;
    string trainname;
    string source;
    string destination;
    string traintime;

public:
    // Maded a Constructor
    Record(int trainnumber = 0,
           string trainname = "",
           string source = "",
           string destination = "",
           string traintime = "")
    {
        this->trainnumber = trainnumber;
        this->trainname = trainname;
        this->source = source;
        this->destination = destination;
        this->traintime = traintime;
    }

    // Getter and Setter methods
    int getTrainNumber() { return trainnumber; }
    void setTrainNumber(int trainnumber) { this->trainnumber = trainnumber; }

    string getTrainName() { return trainname; }
    void setTrainName(string trainname) { this->trainname = trainname; }

    string getSource() { return source; }
    void setSource(string source) { this->source = source; }

    string getDestination() { return destination; }
    void setDestination(string destination) { this->destination = destination; }

    string getTrainTime() { return traintime; }
    void setTrainTime(string traintime) { this->traintime = traintime; }
    
    // Display record details
    void displayRecord()
    {
        cout <<"                                         <<< DISPLAYING TRAIN RECORDS OF " << trainnumber ; cout << " >>>" << endl;
        cout <<"                                                  ->TRAIN NUMBER: " << trainnumber << endl;
        cout <<"                                                  ->TRAIN NAME: " << trainname << endl;
        cout <<"                                                  ->SOURCE OF TRAINN: " << source << endl;
        cout <<"                                                  ->DESTINATION: " << destination << endl;
        cout <<"                                                  ->TRAIN TIME: " << traintime << endl;
        cout << endl;
    }
};

class RailwayReservationSystem
{
private:
    Record records[10];
    int size;

public:
    RailwayReservationSystem()
    {
        size = 0;
    }

    void addTrainRecord()
    {
        if (size <= 10)
        {

            int trainnumber;
            string trainname;
            string source;
            string destination;
            string traintime;

            cout << "<-> <-> <-> ENTER THE DETAILS OF TRAIN TO ADD INTO A RECORD <-> <-> <->" << endl << endl;
            cout << "Enter Train Number: ";
            cin >> trainnumber;
            fflush(stdin);
            cout << "Enter Train Name: ";
            getline(cin, trainname);
            cout << "Enter Train Source: ";
            getline(cin, source);
            cout << "Enter Destination: ";
            getline(cin, destination);
            cout << "Enter Train Time: ";
            cin >> traintime;
            cout << endl << endl;

            records[size] = Record(trainnumber, trainname, source, destination, traintime);
            size++;
        }
        else
        {
            cout << "No more records can be added." << endl;
        }
    }

    void displayAllRecords()
    {
        if (size == 0)
        {
            cout << "No records found." << endl;
        }
        else
        {
            cout << "<< Displaying Train Records >>" << endl;
            for (int i = 0; i < size; i++)
            {
                records[i].displayRecord();
            }
        }
    }

    void searchTrainByNumber()
    {
        int trainnumber;
        cout << "Enter Train Number: ";
        cin >> trainnumber;

        for (int i = 0; i < size; i++)
        {
            cout << "                                              << Searching Train Details >>" << endl << endl;
            if (records[i].getTrainNumber() == trainnumber)
            {
                records[i].displayRecord();
                return;
            }
        }

            cout << "                                            Train with Number " << trainnumber ; 
            cout << " Not Found" << endl << endl;
    }
    void exitSystem()
    {
        cout << "Exiting the System. Bye" << endl;
        exit(0);
    }
};
