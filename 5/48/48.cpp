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

int GetFloor (double num)
{
    int num1 = (int)num;
    if (num >= 0)
    {
        return num1; 
    }
    else
    {
        return num1 - 1;
    }


}


int main()
{
    double number = ReadPositiveNumber();

    cout << "my floor value of " << number << " is " << GetFloor(number) << endl;

    cout << "c++ floor value of " << number << " is " << floor(number) << endl;

    return 0;
}