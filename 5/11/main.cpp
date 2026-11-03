
#include <iostream>
#include <string>     

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

bool IsPalindromeNumber(int Number)
{
    return (Number == InverseNumber(Number));
}

int main()
{

    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?"))==true)
        cout << "Yes, it is Palindrome number" << endl;
    else
        cout << "No, it is not Palindrome number" << endl;

    return 0;
}
