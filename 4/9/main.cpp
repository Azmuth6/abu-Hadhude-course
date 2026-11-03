#include <iostream>
using namespace std;
//void ReadNumbers (int &num1 , int &num2 , int &num3)
//{
//    cout << "enter num1 " ;
//    cin >> num1 ;
//    cout << "enter num2 " ;
//    cin >> num2 ;
//    cout << "enter num3 " ;
//    cin >> num3 ;
//}
//int SumOfNums (int num1 , int num2 , int num3)
//{
//    return num1+num2+num3 ;
//}
//
//void PrintResult(int total)
//{
//    cout <<"sum of three numbers is : "  << total;
//
//}
//
//
//int main()
//{
//    int num1 ,num2 ,num3 ;
//    ReadNumbers(num1 ,num2 ,num3) ;
//    PrintResult (SumOfNums(num1 ,num2 ,num3));
//
//    return 0;
//}






void readarray(int num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "enter num" << i + 1 << ": ";
        cin >> num[i];
    }
}

int sum(int num[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += num[i];
    }
    return total;
}


void PrintResultofarray (int total)
{
    cout <<"sum of three numbers is : "  << total;

}

int main ()
{   int size = 3 ;
    int num [size];
    readarray (num , size) ;
    PrintResultofarray(sum(num , size)) ;
    return 0;
}






