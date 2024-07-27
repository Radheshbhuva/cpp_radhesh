#include <iostream>
#define so std::cout
#define si std::cin
using namespace std;

class Distance
{
    public:
    int feet1;
    int feet2;
    int inch1;
    int inch2;
};
int main()
{
    Distance R1;
    int sum1, sum2, sum3, sum4;
    float sum5;

    so << "Enter your First Measurement:- " << endl;
    so << "Enter feet1:- ";
    si >> R1.feet1;
    so << "Enter inch1:- ";
    si>> R1.inch1;

    so << "Enter your Second Measurement:- " << endl;
    so << "Enter feet2:- ";
    si >> R1.feet2;
    so << "Enter inch2:- ";
    si>> R1.inch2;

    sum1 = (R1.inch1 + R1.inch2)/12;
    sum2 = (R1.feet1 + R1.feet2 + sum1);
    sum3 = (R1.inch1 + R1.inch2)%12;
    sum4 = (R1.inch1 + R1.inch2 + sum1);

    so << "Your Total Distance is " << endl;
    so << "Feet: "<< sum2 << endl;
    so << "Inch: "<< sum4 << endl;
}
