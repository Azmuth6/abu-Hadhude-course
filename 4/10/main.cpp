#include <iostream>
using namespace std;

void ReadNumbers (int &num1 , int &num2 , int &num3)
{
    cout << "enter num1 " ;
    cin >> num1 ;
    cout << "enter num2 " ;
    cin >> num2 ;
    cout << "enter num3 " ;
    cin >> num3 ;
}
int SumOfNums (int num1 , int num2 , int num3)
{
    return num1+num2+num3 ;
}
float avrOfNums (int num1 , int num2 , int num3)
{
    return (float)SumOfNums(num1 ,num2 ,num3) / 3;
}

void PrintResult(float total)
{
    cout <<"sum of three numbers is : "  << total;

}


int main()
{
    int num1 ,num2 ,num3 ;
    ReadNumbers(num1 ,num2 ,num3) ;
    PrintResult (avrOfNums(num1 ,num2 ,num3));

    return 0;
}
