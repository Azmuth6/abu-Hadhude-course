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

bool IsNumInArray(int arr[100] , int length , int Number)
{
    return searchInArray( arr , length , Number ) != -1 ;   // لو -1 موجود هيدي false  و لو اي رقم تاني موجود هيدي true
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
  
    cout << "number you looking for is :  " << Number ;

    if (! IsNumInArray ( arr , arrLength , Number ))  //  لو ادي  true  هتتعكس و تكون false
        cout << "not found  :( \n" ;
    else 
        cout << "found :)  " << endl;
    
    return 0;
}