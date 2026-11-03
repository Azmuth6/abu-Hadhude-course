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


void ReadArray  (int arr[100] , int &length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;   

    for (int i =0  ; i < length ; i++)
        arr[i] = Random_Number(2,100) ;

}

void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ; 

}

void copyOnlyPrime(int arrSource [100] , int arrcopy [100] , int length , int &array2Length)
{
    int j = 0 ;

    for (int i =0  ; i < length ; i++)
    {
        if (isprime(arrSource[i]) == enIsPrime::prime)
        {
            arrcopy[j] = arrSource[i];
            j++;
        }
    }
    array2Length = j;
}


int main ()
{
    srand( (unsigned) time (NULL) ) ; 

    int arrSource[100] ,  arrLength  , arrCopy[100] , array2Length=0;
    ReadArray(arrSource, arrLength);

    cout << "array 1 elements :"<< endl ;
    printArray(arrSource, arrLength);

    copyOnlyPrime(arrSource, arrCopy, arrLength, array2Length);
    cout << "array 2 elements :"<< endl ;
    printArray(arrCopy, array2Length);

        return 0;



}