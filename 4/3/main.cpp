#include <iostream>

using namespace std;
enum enNumberType {odd =1 , even =2};
int ReadNum ()
{
     int number ;
    cout << "Please enter the number " ;
    cin>> number ;
    return number ;
}

enNumberType numbercheaker(int number )
{
    int result = number % 2 ;
    if (result == 0)
        return enNumberType ::even ;
    else if   (result != 0)
        return enNumberType ::odd ;
}

void printNumType(enNumberType NumType)
{
    if (NumType == enNumberType ::even)
        cout << " Num is even" ;
    else if (NumType == enNumberType ::odd)

        cout << " num is odd " ;

}

int main()
{
    printNumType(numbercheaker(ReadNum())) ;

    return 0;
}
