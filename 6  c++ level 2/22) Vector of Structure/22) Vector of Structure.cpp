#include <iostream>
#include <vector>
using namespace std;

struct StEmployee
{
	string FirstName;
	string LastName;
	int Age;
};

void TheExplanation()
{
	vector <StEmployee> VEmployees;
	StEmployee TempEmployee;

	TempEmployee.FirstName = "John";
	TempEmployee.LastName = "Doe";
	TempEmployee.Age = 30;
	VEmployees.push_back(TempEmployee);

	TempEmployee.FirstName = "Jane";
	TempEmployee.LastName = "Smith";
	TempEmployee.Age = 25;

	VEmployees.push_back(TempEmployee);

	TempEmployee.FirstName = "Alice";
	TempEmployee.LastName = "Johnson";
	TempEmployee.Age = 28;

	VEmployees.push_back(TempEmployee);

	for (StEmployee& Employee : VEmployees)
	{
		cout << "First Name: " << Employee.FirstName << endl;
		cout << "Last Name: " << Employee.LastName << endl;
		cout << "Age: " << Employee.Age << endl;
		cout << "------------------------" << endl;
	}
}

void AskForInPut(vector <StEmployee>& VEmployee)
{
	char choice;
	StEmployee TempEmployee;
	do
	{
		cout << "Enter First Name ";
		cin >> TempEmployee.FirstName;
		
		cout << "Enter Last Name  ";
		cin >> TempEmployee.LastName;
		
		cout << "Enter Age        ";
		cin >> TempEmployee.Age;
		
		VEmployee.push_back(TempEmployee);

		cout << "Do you want to add another employee? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
	cout << endl;
}

void PrintEmployees(vector <StEmployee> & VEmployee)
{
	for (StEmployee& Employee : VEmployee)
	{
		cout << "First Name: " << Employee.FirstName << endl;
		cout << "Last Name: " << Employee.LastName << endl;
		cout << "Age: " << Employee.Age << endl;
		cout << "------------------------" << endl;
	}

}

void HomeWorkSolution()
{
	vector <StEmployee> VEmployee;
	AskForInPut(VEmployee);
	PrintEmployees(VEmployee);
}

int main()
{
	HomeWorkSolution();

}

