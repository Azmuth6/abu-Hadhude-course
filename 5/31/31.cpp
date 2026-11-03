#include<iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;
int Random_Number (int from , int to)
{
    int random = rand() % (to - from +1 ) + from ;
    return random ;
}

void swap (int &a , int &b)
{
    int temp = a ;
    a = b ;
    b = temp ;
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

void ReadArray  (int arr[100] , int length)
{ 
    for (int i =0  ; i < length ; i++)
        arr[i] = i+1 ;

}

void ShuffleArray(int arr [100], int arrlength)
{
    for (int i =0 ; i < arrlength ; i++)
    {
        swap(arr[Random_Number(1, arrlength - 1 )], arr[Random_Number(1, arrlength - 1)]);
    }

}

void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << "  " ;

    cout << endl ; 

}


int main ()
{
    srand( (unsigned) time (NULL) ) ;
    int arrLength = ReadPositiveNumber("Enter the length of the arrays : \n");
    int arr[100] ;

    
    ReadArray(arr, arrLength);
    cout << "array 1 " << endl;
    printArray(arr, arrLength);
    
    
    ShuffleArray(arr,arrLength);
    cout << "array 2 -> " <<endl ;
    printArray(arr, arrLength);





    return 0;
}