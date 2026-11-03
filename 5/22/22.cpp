#include <iostream>

using namespace std ;

int ReadPositiveNumber(string Message)
{
    int Number = 0; 
    do
    {
        cout << Message ;
        cin >> Number;          
    } while (Number <= 0);      
    return Number;
}
void ReadArray  (int arr[100] , int &length)
{
    cout << "\nEnter number of elements:\n";
    cin >> length;  
    cout << "\nEnter array elements: \n";
    for (int i =0  ; i < length ; i++)
    {
        cout << "Element [" << 1+i << "]  : " ;    
        cin >> arr [i] ;
    }
    cout << endl; 
}   


void printArray (int arr[100] , int length)
{
    for (int i =0  ; i < length ; i++)
        cout << arr[i] << " " ;

    cout << endl ;

}

void TimesRepeated(int num ,int arr[100] , int length)
{
    int repeated =0;
    
    for (int i =0  ; i < length ; i++)
    {
            if (arr[i] == num)
                repeated ++ ;
             
    }


}


int main () 
{
    int arr[100] , NumberToCheck , arrLength ;  
       
    ReadArray(arr, arrLength);

    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    cout << "\nOriginal array: ";
    printArray(arr, arrLength);

    cout << "\nNumber " << NumberToCheck;
    cout << " is repeated ";
    TimesRepeated(NumberToCheck, arr, arrLength)  ;
    return 0 ;
}