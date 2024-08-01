#include <iostream>
using namespace std;

int main()
{
    int seconds, hours, minutes;

    cout << "Enter the Time in Seconds: ";
    cin >> seconds;

    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;

    cout << "Time in HH:MM:SS format: " << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}