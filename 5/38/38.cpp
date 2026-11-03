#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random_Number (int from , int to)
{
    int random = rand() % (to - from +1 ) + from ;
    return random ;
}

void printArrayElements(int arr[100] , int arrayLength)
{
    for (int i = 0 ; i < arrayLength ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

void ReadArray  (int arr[100] , int &arraylength)
{
    cout << "Enter number of elements : \n";
    cin >> arraylength;
   
    for (int i =0  ; i < arraylength ; i++)
        arr[i] = Random_Number(1,100) ;
}


void AddArrayElements  (int num, int array [100] , int & length)
{
    array[length] = num ;
    length ++ ;
}

void PrintOddNumbers(int arraySource[100] , int arraycopy [100] , int arrayLengthSource , int & arrayLengthCopy)
{
    for (int i = 0; i < arrayLengthSource; i++)
    {
        if (arraySource[i] % 2 != 0) // Check if the number is odd and not contained || =1 in if statement
            AddArrayElements(arraySource[i], arraycopy, arrayLengthCopy);
    }
}


int main ()
{
    int arrayLengthCopyOdd = 0, arrayLengthSource = 0, arraySource[100], arrayCopyOdd[100];

    ReadArray(arraySource, arrayLengthSource);
    PrintOddNumbers(arraySource, arrayCopyOdd, arrayLengthSource, arrayLengthCopyOdd);

    cout << "array 1 ->" << endl;
    printArrayElements(arraySource, arrayLengthSource);

    cout << "\n\narray  odd nums ->" << endl;
    printArrayElements(arrayCopyOdd, arrayLengthCopyOdd);

    return 0;

}
