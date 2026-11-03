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


int CountDigitFrequency(short DigitToCheck, int Number)
{
    int FreqCount = 0 , Reminder = 0;
    while (Number > 0)
    {
        Reminder = Number % 10;
        Number /= 10;
        if (Reminder == DigitToCheck)
        {
            FreqCount++;
        }
    }
    return FreqCount;
}

int main()
{ 
    int Number = ReadPositiveNumber("Please enter the main number?");
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");
    cout << "\nDigit " << DigitToCheck << " Frequency is "
    << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";    return 0;
}
