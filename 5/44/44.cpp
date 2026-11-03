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
        arr[i] = RandomNumber(-100, 100);

    }
}


short NumOfPositiveNumbersInArray(int arr[100], int arrLength) {
    short positiveCount = 0;
    for (int i = 0; i < arrLength; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        }
    }
    return positiveCount;

}

int main()
{

    srand((unsigned)time(NULL)); 

    int arr[100], arrLength = 0;
    FillArray(arr, arrLength);
    cout << "\nArray Elements:\n";
    printArrayElements(arr, arrLength);

    short positiveCount = NumOfPositiveNumbersInArray(arr, arrLength);
    cout << "Number of Positive Elements: " << positiveCount << endl;

    return 0;
}
