#include <iostream>
#define so std::cout
#define si std::cin

void evenelements(int* arr, int size) 
{
    so << "Even elements in the array are: ";
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] % 2 == 0) 
        {
            so << arr[i] << " ";
        }
    }
    so << std::endl;
}

int main() 
{
    int size;
    so << "Enter the size of Your array: ";
    si>> size;

    int* arr = new int[size];

    so << "Enter Elements of this array: ";
    for (int i = 0; i < size; i++) 
    {
        si >> arr[i];
    }

    so << "Your given Input is: ";
    for (int i = 0; i < size; i++) 
    {
        so << arr[i] << " ";
    }
    so << std::endl;

    evenelements(arr, size);
}