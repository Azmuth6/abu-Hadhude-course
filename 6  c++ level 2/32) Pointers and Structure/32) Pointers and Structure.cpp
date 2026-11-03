#include <iostream>

using namespace std;

struct stEmployee
{
    string name;
    int salary;
};

int main()
{
    stEmployee Employee1, * Ptr;

    Employee1.name = "ali ahmed ";
    Employee1.salary = 4000;

    cout << Employee1.name << endl;
    cout << Employee1.salary << endl;

    Ptr = &Employee1;

    cout << "pointer : " << endl;

    cout << Ptr->name << endl;
    cout << Ptr->salary;

    return 0;

}

