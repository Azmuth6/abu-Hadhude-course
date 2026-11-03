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
        arr[i] = Random_Number(1,100) ;
    
} 

void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ;

}

int  Max ( int arr[100] , int length)
{   int Max = 0 ;
    for (int i =0  ; i < length ; i++)
    {
       if (arr[i] > Max)
        {
            Max = arr[i];
        }

    }

    return Max;
}


int main ()
{
     srand( (unsigned) time (NULL) ) ; 

    int arr[100] ,  arrLength ;     
    ReadArray(arr, arrLength);

    printArray(arr , arrLength) ;

    cout << "Max is -> " << Max(arr , arrLength) << endl ;

}