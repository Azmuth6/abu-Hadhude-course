#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void printArrayElements(int arr[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int RandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void FillArray(int arr[100], int &arrLength) {
    arrLength = 0;
    cout << "enter num of elements in array: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(0, 100);
        
    }
}

int NumOfEvenNumbersInArray(int arr[100], int arrLength) {
    int evenCount = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    return evenCount;

}

int main()
{

    srand((unsigned)time(NULL)); 

    int arr[100], arrLength = 0;
    FillArray(arr, arrLength);
    cout << "\nArray Elements:\n";
    printArrayElements(arr, arrLength);

    int evenCount = NumOfEvenNumbersInArray(arr, arrLength);
    cout << "Number of Even Elements: " << evenCount << endl;

    return 0;
}
