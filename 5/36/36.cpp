#include<iostream>

using namespace std;


int ReadPositiveNumber()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;

    while (number <= 0)
    {
        cout << "Please enter a positive number: ";
        cin >> number;
    }
    return number;
}


void addArrayElements(int number , int arr[100] , int &arrayLength)
{
    arrayLength ++ ;
    arr [arrayLength -1] = number ;
}

void InputUserNumbersInArray( int arr[100] , int &arrayLength)
{
    bool AddMore = true ;
    do
    {   
        addArrayElements(ReadPositiveNumber() , arr , arrayLength ) ;

        cout << "Do you want to add more numbers ? [0] false , [1] true : ";
        cin >> AddMore ;

    } while (AddMore);


}

void PrintarrayNumbers(int arr[100] , int count)
{
    for (int i = 0 ; i < count ; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl << "The number of elements in the array is : " << count << endl;
}

int main ()
{
    int arr[100] , arrayLength = 0 ;
    InputUserNumbersInArray ( arr , arrayLength) ; 

    cout << "arrayLength = " << arrayLength << endl ;

    cout << "The numbers in the array are : " << endl ;

    PrintarrayNumbers(arr , arrayLength) ;

    return 0 ;
}









