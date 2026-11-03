#include <iostream>
using namespace std;

class clsPerson
{

private:

    string _FirstName;

public:


    void SetFirstName(string FirstName) {

        _FirstName = FirstName;

    }

    string GetFirstName() {

        return _FirstName;

    }

    __declspec(property(put = SetFirstName, get = GetFirstName)) string Name;

    /*
            __declspec(property(get = GetFirstName, put = SetFirstName)) string Name;
            NO Difference
    */


};

int main()

{

    clsPerson Person1;

    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() << endl;

    //instead of the above we only write this
    Person1.Name = "Mohammed";
    cout << Person1.Name;

    system("pause>0");
    return 0;
};

