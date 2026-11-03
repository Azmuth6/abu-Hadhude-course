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

void printNum (int number)
{
    for (int i = 65 + number - 1; i >= 65; i--) //  65 + number - 1 علشان تبدا من A // for make A = 65 , B = 66 , C = 67 ... Z = 90 in ASCII table.
     {
       for  (int j = 65; j <= i; j++) 
       {
           cout <<char(i) ;  
       }
       cout << endl;
   }

}

int main()
{
    printNum(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
