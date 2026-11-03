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
    int FreqCount = 0 , Reminder = 0 ;  
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

void PrintAllDigitsFrequencey(int Number)
{
    cout << endl; 
    
    for (int i = 0; i < 10; i++)
    { 
        short DigitFrequency = 0;                  
        DigitFrequency = CountDigitFrequency(i, Number); 

        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is " 
                 << DigitFrequency << " Time(s).\n";
        }
    }
}

int main()
{
    
    int Number = ReadPositiveNumber("Please enter the a number?");
    PrintAllDigitsFrequencey(Number);
    
    return 0;  
}