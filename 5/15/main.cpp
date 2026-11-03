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

void printLetters (int number)
{
   for (int i = 65 ; i < number+65 ; i++)
   {
       for  (int j = 65; j <= i; j++)
       {
           cout << char(i) ;
       }
       cout << endl;
   }

}

int main()
{
    printLetters(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
