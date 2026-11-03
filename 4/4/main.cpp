#include <iostream>

using namespace std;

struct stinfo
{
    int age ;
    bool hasDrivingLicer ;
};
stinfo readInfo()
{
    stinfo Info ;
    cout << "enter your age " ;
    cin >> Info.age ;
    cout <<"Do you have a driving license? (1 for Yes, 0 for No): " ;
    cin >> Info.hasDrivingLicer ;
    return Info;
}

bool isAccepted(stinfo Info)
{
    return (Info.age >21 && Info.hasDrivingLicer==1) ;
}

void printResult (stinfo Info)
{
    if (isAccepted(Info))
        cout << "ok" ;
    else
        cout <<"not ok " ;
}

int main()
{
    printResult(readInfo()) ;
    return 0;
}
