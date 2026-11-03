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

int GetSQRT(int number)
{
    int sqrt = 0;
    while (sqrt * sqrt < number)
        sqrt++;
    
    if (sqrt * sqrt == number)
        return sqrt;
    
    else
        return -1;
    
}

float MySqrt(float Number)
{
    return pow(Number, 0.5);
}

int main()
{
    int number = ReadPositiveNumber();

    cout << "my sqrt value of " << number << " is " << GetSQRT(number) << endl;

    cout << "c++ sqrt value of " << number << " is " << sqrt(number) << endl;

    cout << "DR sqrt value of " << number << " is " << MySqrt(number) << endl;
    return 0;
}