#include <iostream>

using namespace std;

int main()
{
    int arr[4] = { 10 , 20 , 30 , 40 };
    int* ptr = arr;

    //ptr is equivalent to &arr[0];
    //ptr + 1 is equivalent to &arr[1];
    //ptr + 2 is equivalent to &arr[2];
    //ptr + 3 is equivalent to &arr[3];


    cout << "address is " <<endl ;
    for (int i = 0; i < 4; i++)
    {
        cout << ptr + i << endl ; 

    }

    cout << "\nvalue is  : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << *(ptr + i) << endl;

    }

}

