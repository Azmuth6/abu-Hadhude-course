#include <iostream>
#include <string>
using namespace std;
int readNumber()
{
    int num ;
    cout << "enter the number " ;
    cin >> num ;
    return num ;
}
float halfNumber (int num )
{
    return (float) num / 2 ;
}

void printResult (int num)
{
    string result = "Half of " + to_string(num) + " is :" + to_string(halfNumber(num)) ;
    cout << result ;
}


int main()
{
    printResult(readNumber()) ;
    return 0;
}
