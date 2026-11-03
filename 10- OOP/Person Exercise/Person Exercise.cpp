#include <iostream>

using namespace std;

class clsPerson
{
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}


	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	void setEmail(string Email)
	{
		_Email = Email;
	}
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	int ID ()
	{
		return _ID;
	}

	string FirstName()
	{
		return _FirstName;
	}
	string LastName()
	{
		return _LastName;
	}
	string FullName()
	{
		return  _FirstName + " " + _LastName;
	}
	string Email()
	{
		return _Email;
	}
	string Phone()
	{
		return _Phone;
	}


	void  Print()
	{
		cout << "\n---------------------------------------------\n";
		cout << "ID         : " << _ID << endl;
		cout << "First Name : " << _FirstName << endl;
		cout << "Last Name  : " << _LastName << endl;
		cout << "Full Name  : " << FullName() << endl;
		cout << "Email      : " << _Email << endl;
		cout << "Phone      : " << _Phone << endl;
		cout << "\n---------------------------------------------\n";
	}

	void SendMail(string subject, string body)
	{
		cout << "\n\nMessage Set By Email : " << _Email;
		cout << "\nbody    : " << body;
		cout << "\nsubject : " << subject;
	}

	void SendSMS(string subject)
	{
		cout << "\n\nMessage Set By Phone number : " << _Phone;

		cout << "\nsubject : " << subject;
	}

};


int main()
{
	clsPerson Person1(10, "Salah", "Ahmed", "SAmll@gmail.com", "102202");

	Person1.Print();

	Person1.SendMail("Hi", "How are you?");

	Person1.SendSMS("Hello");

	system("pause>0");
	return 0;

}