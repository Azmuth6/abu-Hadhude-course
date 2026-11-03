#include <iostream>

using namespace std;
string readName()
{
    string name ;
    cout << "enter your name " ;
    getline(cin,name) ;
    return name ;
}

void print_name(string name )
{
    cout << "hello " << name ;
}


int main()
{
    print_name(readName()) ;
    return 0;
}
