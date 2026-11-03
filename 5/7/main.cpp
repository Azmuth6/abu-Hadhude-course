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

int InverseNumber (int number)
{
    int remainder =0 , inverse =0  ;

    while (number > 0)
    {
        remainder = number %10 ;
        number  = number /10 ;
        inverse = inverse * 10 + remainder ;
    }
        return inverse;
}

int main()
{
    cout << InverseNumber(ReadPositiveNumber("Please enter a positive number?"))
    << "inverse number is : " << endl; 
    return 0;
}
