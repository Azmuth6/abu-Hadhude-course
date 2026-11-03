#include <iostream>
#include <string>
using namespace std;
struct stinfo
{
    string firstName ;
    string lastName;
};
stinfo ReadInfo ()
{
    stinfo info ;
    cout <<"enter your first name : ";
    cin >> info.firstName ;
    cout <<"enter your last name : ";
    cin >> info.lastName ;
    return info;
}
string setFullname (stinfo info , bool reversed)
{
    string fullname ;
    if(reversed)
        fullname = info.lastName +" "+info.firstName ;
    else
        fullname = info.firstName +" "+info.lastName ;
    return fullname ;
}


void getFullname (string fullname)
{
    cout <<"your full name is : " << fullname ;
}

int main()
{
    getFullname(setFullname(ReadInfo(),false)) ;
    return 0;
}
