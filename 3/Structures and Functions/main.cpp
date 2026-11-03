#include <iostream>
#include <string>
using namespace std;
struct strinfo
{
    string name ;
    int age ;
    string city ;
    string country ;
    int salary ;
    char gender ;
    bool married = true;
};
void readinfo (strinfo &info)
{
   cout << "enter name : " ;
   getline(cin,info.name);
   cout << "enter age : ";
   cin >> info.age ;
   cout << "enter city : ";
   cin >> info.city ;
   cout << "enter country : ";
   cin >> info.country ;
   cout << "enter salary : ";
   cin >> info.salary ;
   cout << "enter gender : ";
   cin >> info.gender ;
   cout << "Are you married? (1 for Yes, 0 for No): ";
   cin >> info.married;
}
void printinfo (strinfo info)
{
    cout << "***************************************"<< endl ;
    cout << "your  name is : " << info.name <<endl ;
    cout << "your age is : " << info.age <<endl ;
    cout << "your city is : " << info.city <<endl ;
    cout << "your country is : " << info.country <<endl ;
    cout << "your salary is : " << info.salary <<endl ;
    cout << "your gender is : " << info.gender <<endl ;
    cout << "your life is : " << info.married <<endl ;
    cout << "***************************************"<< endl ;
}
void thing ()
{
    string any_thing ;
    cout << "how can i help you ? ";
    getline(cin, any_thing);
    cout <<"sure i will  " << any_thing<<endl ;
}
int main()
{

    thing () ;
    strinfo person1;
    readinfo(person1);
    printinfo(person1);

    return 0;
}



