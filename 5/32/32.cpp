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
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[(arrLength - 1) - i];  // Copying in reverse order 0=9, 1=8, 2=7, 3=6, 4=5
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

    int arr1[100], arr2[100];

    ReadArray(arr1, arrLength);
    cout << "Array 1: " << endl;
    PrintArray(arr1, arrLength);

    CopyArrayInReverseOrder(arr1, arr2, arrLength);
    cout << "Array 2 (Reversed): " << endl;
    PrintArray(arr2, arrLength);

    return 0;
}