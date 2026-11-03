#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int sumOfNumbers (int number)
{
    int remainder =0, sum =0;  ;

    while (number > 0)
    {
        remainder = number %10 ;
        number  = number /10 ;
        sum += remainder ;
    }
        return sum ;
}

int main()
{
        cout << sumOfNumbers(ReadPositiveNumber("Please enter a positive number?")) ;

    return 0;
}
