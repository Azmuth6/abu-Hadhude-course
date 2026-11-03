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



void ReadArray  (int arr[100] , int length)
{ 
    for (int i =0  ; i < length ; i++)
        arr[i] = Random_Number(2,100) ;

}

void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ; 

}

void SumOfTwoArrays (int arr1 [100] , int arr2 [100] ,int arr3 [100] ,int length )
{
    for (int i =0  ; i < length ; i++)
    {
       arr3[i] = arr1[i] + arr2[i];
    }

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


int main ()
{
    srand( (unsigned) time (NULL) ) ; 
   
    int arrLength = ReadPositiveNumber("Enter the length of the arrays : \n");


    int array1[100]  , array2[100] , array3[100];
    ReadArray(array1, arrLength);

    cout << "array 1 elements : \n"<< endl ;
    printArray(array1, arrLength);

    ReadArray(array2, arrLength);
    cout << "array 2 elements : \n"<< endl ;
    printArray(array2, arrLength);
    
    SumOfTwoArrays(array1, array2, array3, arrLength);

    cout << "array 3 elements : \n"<< endl ;
    printArray(array3, arrLength);

        return 0;



}