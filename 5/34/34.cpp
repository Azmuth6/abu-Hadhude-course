#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Random_Number (int from , int to)
{
    int random = rand() % (to - from +1 ) + from ;
    return random ;
}

void ReadArray  (int arr[100] , int length)
{ 
    for (int i =0  ; i < length ; i++)
        arr[i] = Random_Number(2,100) ;
}

void PrintArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ;
}

int ReadPositiveNumber(string Message)
{
    int number;
    cout << Message;
    cin >> number;

    while (number <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> number;
    }
    return number;
}

short searchInArray(int arr[100] , int length , int Number )
{
    for (short i = 0 ; i < length ; i++)
    {
        if (arr[i] == Number)
        {
           return i;
        }
    }
    return -1;

}

int main ()
{
    srand( (unsigned) time (NULL) ) ;

    int arrLength = ReadPositiveNumber("Enter the length of the arrays : \n");

    int arr[100];

    ReadArray(arr , arrLength); 

    cout << "Arrays numbers -> " << endl;
    PrintArray(arr, arrLength);

    int Number = ReadPositiveNumber("Enter number you want to search for : ");
  
    short NumberPosition =  searchInArray(arr,arrLength,Number) ;

    if (NumberPosition == -1)
    {

        cout << "not found \n" ;
    }
    else 
    {
        cout << "number position -> " << NumberPosition  << endl;
        cout << "number order ->  "    << NumberPosition +1 ;

    }


    return 0;
}