#include <iostream>
#include <string>

using namespace std;
string ReadString()
{
	string input;
	cout << "Enter a string: ";
	getline(cin, input);
	return input;
}
char invertCase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

string invertCase(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = invertCase(str[i]);
	}
	return str;
}

int main()
{
	string inputString = ReadString();
	cout << "Inverted case: " << invertCase(inputString) << endl;

	return 0;

}
