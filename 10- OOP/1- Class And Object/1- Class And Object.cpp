#include <iostream>

using namespace std;

class clsPerson
{
	int x;  //Private

public:
	string FirstName;
	string LastName;

	string FullName()
	{
		return FirstName + " " + LastName;
	}


};

int main()
{
	clsPerson Person1;

	Person1.FirstName = "Salah";
	Person1.LastName = "Ahmed";

	cout << Person1.FullName() << endl;

}