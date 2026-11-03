#include <iostream>

using namespace std;
enum enPassFail {Pass =1 , Fail = 2};
int ReadMark ()
{
    int Mark ;
    cout << "Enter your Mark \n";
    cin >> Mark ;
    return Mark ;
}

enPassFail checkMark(int Mark)
{
    if (Mark >=50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail ;
}

void PrintResult (int Mark)
{
    if (checkMark(Mark)==enPassFail::Pass)
        cout << "pass";
    else
        cout <<"fail" ;
}


int main()
{
    PrintResult(ReadMark()) ;

    return 0;
}
