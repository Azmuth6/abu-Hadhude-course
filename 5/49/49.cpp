#include <iostream>
#include <cmath> 
using namespace std;
double ReadPositiveNumber()
{
    double number;
    cout << "Enter the number : ";
    cin >> number;

    while (number <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> number;
    }
    return number;
}

float GetFractionPart(float Number)
{
    
    return Number - int(Number);
}


int getCeil(double Number)
{
    
     // If the number has a fractional part greater than zero, round up if positive.
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;  // Round up for positive numbers.
        else
            return int(Number);  // Keep the integer part for negative numbers.
    }
    else
        return Number;  // If the number is already an integer, return it as is.
}

int main()
{
    double number = ReadPositiveNumber();

    cout << "my ceil value of " << number << " is " << getCeil(number) << endl;

    cout << "c++ ceil value of " << number << " is " << ceil(number) << endl;

    return 0;
}