#include <iostream>
using namespace std;

void printArrayElements(int arr[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void FillArray(int arr[100], int &arrLength) {
    arrLength = 0;

    arr[0] = 10; arrLength++;
    arr[1] = 20; arrLength++;
    arr[2] = 30; arrLength++;
    arr[3] = 30; arrLength++;
    arr[4] = 20; arrLength++;
    arr[5] = 10; arrLength++;
}

bool IsArrayPalindrome(int arr[100] , int arrlength)
{
    for (int i =0 ; i < arrlength ; i++)
        {
            if (arr[i] != arr[arrlength - i -1])
                    return false ;
        }
        return true ;
}

int main ()
{

    int arr[100] , arrlength  =0  ;

    FillArray(arr , arrlength) ;

    cout << "\nArray Elements:\n";
    printArrayElements(arr , arrlength);

    if (IsArrayPalindrome(arr , arrlength))
            cout << "\nYes array is Palindrome\n";
    else
        cout << "\nNO array is NOT Palindrome\n";

    return 0 ;
}