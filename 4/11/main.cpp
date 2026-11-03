#include <iostream>
using namespace std;


enum enPassFail {Pass =1 , Fail =2};
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

enPassFail ChickAvr (float total)
{
    if (total >=50)
        return enPassFail::Pass ;
    else
        return enPassFail::Fail;
}
void PrintResult(float total)
{
    cout <<"your avr is : "  << total<<endl;
    if (ChickAvr(total) == enPassFail::Pass)
        cout << "you pass" ;
    else
        cout << "you fail" ;

}

int main()
{
    int num1 ,num2 ,num3 ;
    ReadNumbers(num1 ,num2 ,num3) ;
    PrintResult (avrOfNums(num1 ,num2 ,num3));

    return 0;
}
