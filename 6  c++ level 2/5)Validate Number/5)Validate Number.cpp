

#include <iostream>
using namespace std;

int ReadNumber()
{
    int num;
	cout << "Please enter a valid number: ";
    cin >> num;
     
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input.\nPlease enter a valid number: ";
		cin >> num;
    }
	return num;
}

int main()
{
	cout << "your number is -> " << ReadNumber() << endl;
}

