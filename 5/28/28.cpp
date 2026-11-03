#include <iostream>
#include <cstdlib>    
#include <ctime>
#include <string>
using namespace std;



int Random_Number (int from , int to)
{
    
    int random = rand() % (to - from +1 ) + from ;
    return random ;
    
}
void ReadArray  (int arr[100] , int &length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;   
   
    for (int i =0  ; i < length ; i++)
        arr[i] = Random_Number(0,100) ;
    
} 

void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ; 

}

void copy (int arrSource [100] , int arrcopy [100] , int length)
{
    for (int i =0 ; i < length ; i++ )
        arrcopy[i] = arrSource[i];

}


int main ()
{
     srand( (unsigned) time (NULL) ) ; 

    int arrSource[100] ,  arrLength  , arrCopy[100];
    ReadArray(arrSource, arrLength);

    cout << "array 1 elements :"<< endl ;
    printArray(arrSource, arrLength);

    copy(arrSource, arrCopy, arrLength);
    cout << "array 2 elements :"<< endl ;
    printArray(arrCopy, arrLength);

        return 0;

}