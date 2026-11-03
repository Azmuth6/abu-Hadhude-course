#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


enum enIsPrime {prime=1 , notPrime =2};

enIsPrime isprime(int num)
{
    int M = round(num/2);

    for (int i = 2; i<=M ; i++)
    {
        if (num % i ==0)
            return notPrime;
    }
    return prime;
}



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

void PrintPrimeNumbers(int arraySource[100] , int arraycopy [100] , int arrayLengthSource , int & arrayLengthCopy)
{
    for (int i = 0; i < arrayLengthSource; i++)
    {
        if (isprime(arraySource[i]) == enIsPrime::prime)
            AddArrayElements(arraySource[i], arraycopy, arrayLengthCopy);
    }
}


int main ()
{
    int arrayLengthCopyPrime = 0, arrayLengthSource = 0, arraySource[100], arrayCopyPrime[100];

    ReadArray(arraySource, arrayLengthSource);
    PrintPrimeNumbers(arraySource, arrayCopyPrime, arrayLengthSource, arrayLengthCopyPrime);

    cout << "array 1 ->" << endl;
    printArrayElements(arraySource, arrayLengthSource);

    cout << "\n\narray  prime nums ->" << endl;
    printArrayElements(arrayCopyPrime, arrayLengthCopyPrime);

    return 0;
}