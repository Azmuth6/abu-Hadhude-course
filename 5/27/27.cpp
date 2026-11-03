#include <iostream>
#include <cstdlib>    
#include <ctime> 
using namespace std ;



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

int sum (int arr[100] , int length) 
{
    int sum = 0 ;
    for (int i = 0 ; i < length ; i++)
         sum +=arr[i];

    return sum ;

}

float  Average (int arr[100] , int length)
{

    return (float)  sum(arr , length) / length;

}

int main ()
{
     srand( (unsigned) time (NULL) ) ; 

    int arr[100] ,  arrLength ;     
    ReadArray(arr, arrLength);

    printArray(arr , arrLength) ;

    cout << "sum of elements is -> " << sum(arr , arrLength) << endl ;

    cout << "Average of elements is -> " << Average (arr , arrLength) << endl ;

        return 0;

}