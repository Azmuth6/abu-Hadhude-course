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

int  min ( int arr[100] , int length)
{   int min = 100 ;
    for (int i =0  ; i < length ; i++)
    {
       if (arr[i] < min)
        {
            min = arr[i];
        }

    }

    return min;
}


int main ()
{
     srand( (unsigned) time (NULL) ) ; 

    int arr[100] ,  arrLength ;     
    ReadArray(arr, arrLength);

    printArray(arr , arrLength) ;

    cout << "Min is -> " << min(arr , arrLength) << endl ;
    return 0;
}