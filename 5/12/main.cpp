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
   for (int i = number ; i >= 1 ; i--)
   {
       for  (int j = 1; j <= i; j++)
       {
           cout << i ;
       }
       cout << endl; 
   } 

}




int main()
{
    printNum(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
