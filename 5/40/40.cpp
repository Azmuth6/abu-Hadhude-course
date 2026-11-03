#include<iostream>
using namespace std;


void printArrayElements(int arr[100] , int arrayLength)
{
    for (int i = 0 ; i < arrayLength ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
void FillArray(int arr[100], int &arrLength)
{
    arrLength = 0 ;  

    arr[0] = 10;  arrLength++;
    arr[1] = 10;  arrLength++;
    arr[2] = 10;  arrLength++;
    arr[3] = 50;  arrLength++;
    arr[4] = 50;  arrLength++;
    arr[5] = 70;  arrLength++;
    arr[6] = 70;  arrLength++;
    arr[7] = 70;  arrLength++;
    arr[8] = 70;  arrLength++;
    arr[9] = 90;  arrLength++;
}

short FindNumPerPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
}


bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumPerPositionInArray(Number, arr, arrLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
{
   
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
             AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

int main()
{
    int arr[100], arrLength = 0, arrDistinct[100], arrDistinctLength = 0;


    FillArray(arr, arrLength);
    cout << "Original Array: ";
    printArrayElements(arr, arrLength);

    CopyDistinctNumbersToArray(arr, arrDistinct, arrLength, arrDistinctLength);
    
    cout << "Distinct Numbers Array: ";
    printArrayElements(arrDistinct, arrDistinctLength);

    return 0;
}