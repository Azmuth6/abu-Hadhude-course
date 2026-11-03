#include <iostream>
using namespace std;
int ReadPositiveNumber()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;

    while (number <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> number;
    }
    return number;
}



int AbstractSign(int num)
{
    if (num >= 0)
        return num;
    else
        return -num;
}


int main()
 {
    int number = ReadPositiveNumber();


    cout << "my absolute value of " << number << " is " << AbstractSign(number) << endl;

    cout << "c++ absolute value of - " << number << " is " << abs(number) << endl;


    return 0;
}