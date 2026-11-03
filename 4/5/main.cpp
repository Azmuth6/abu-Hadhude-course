#include <iostream>

using namespace std;

struct stinfo
{
    int age ;
    bool hasDrivingLicer ;
    bool hasRecommedation ;
};
stinfo readInfo()
{
    stinfo Info ;
    cout << "enter your age " ;
    cin >> Info.age ;
    cout <<"Do you have a driving license? (1 for Yes, 0 for No): " ;
    cin >> Info.hasDrivingLicer ;
    cout << "do you have a recommendation ? (1 for Yes, 0 for No):" ;
    cin >> Info .hasRecommedation ;
    return Info;
}

bool isAccepted(stinfo Info)
{
    if (Info.hasRecommedation)
        return true ;

    else
        return (Info.age >21 && Info.hasDrivingLicer) ;
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
