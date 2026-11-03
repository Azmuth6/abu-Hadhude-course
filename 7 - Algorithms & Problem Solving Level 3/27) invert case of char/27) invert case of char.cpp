#include <iostream>
#include <string>

using namespace std;

char invertCase(char c)
{
	return isupper(c) ? tolower(c) :  toupper(c) ;
}

int main()
{
	char inputChar;
	cout << "Enter a character: ";
	cin >> inputChar;

	cout << "Inverted case: " << invertCase(inputChar) << endl;

	return 0;

}
