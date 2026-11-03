#include <iostream>
#include <cmath> // for round function
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

double GetRoundedEndNum(double num)
{/*
    double round = num ;
    round =round - (int)num ;
    return round;*/

    return num - (int)num; // This returns the fractional part of the number
}

int GetRound (double num)
{
    double round = GetRoundedEndNum(num);
    int num1= (int)num;
    if (num1 >= 0  )
    {
        if (round >= 0.5)
            return num1 + 1;
        else
            return num1;
    }
    else
    {
        if (round >= 0.5)
            return num1 - 1;
        else
            return num1;
    }

}


int main()
{
    double number = ReadPositiveNumber();

    cout << "my rounded value of " << number << " is " << GetRound(number) << endl;

    cout << "c++ rounded value of " << number << " is " << round(number) << endl;

    return 0;
}