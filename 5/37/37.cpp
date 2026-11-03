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
        arr[i] = Random_Number(0,100) ;
}

void addarrayElements (int num , int arr [100] , int & arrayLength)
{
    arr[arrayLength] = num ;
    arrayLength++ ;
}

void copyElementsFromArray(int arraySource[100] , int arraycopy [100] , int arrayLengthSource , int & arrayLengthCopy)
{
    for (int i =0 ; i < arrayLengthSource ; i++)
        addarrayElements(arraySource[i] , arraycopy , arrayLengthCopy) ;

}

int main ()
{
    int arrayLengthCopy =0 , arrayLengthSource = 0 , arraySource [100] , arrayCopy [100];

    copyElementsFromArray(arraySource , arrayCopy , arrayLengthSource , arrayLengthCopy) ;

    ReadArray(arraySource, arrayLengthSource) ;
    cout  << "array 1 ->" << endl ; 
    printArrayElements(arraySource, arrayLengthSource);

    cout << "array  copy ->" << endl ;
    printArrayElements (arrayCopy , arrayLengthCopy) ;

}

