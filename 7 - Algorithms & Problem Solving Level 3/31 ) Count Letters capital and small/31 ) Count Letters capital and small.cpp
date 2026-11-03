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

char ReadFind()
{
	char input;
	cout << "Enter Char you Want to Find : ";
	cin >> input;
	return input;
}

char  InvertLetterCase(char char1)
{ return isupper(char1) ? tolower(char1) : toupper(char1); }


int countNumberOfLetters(string str, char Record,bool WhatIS = true)
{

	int count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (WhatIS)
		{
			if (str[i] == Record)
			{
				count++;
			}
		}
		else
		{
			if (tolower(str[i]) == tolower(Record))
			{
				count++;
			}
		}
	}
	return count;

}



int main()
{
	string inputString = ReadString();
	char FindChar = ReadFind();


	cout << "Number of letters " << FindChar << " is : " << countNumberOfLetters(inputString, FindChar) << endl;

	cout << "Number of letters " << FindChar << " OR " << InvertLetterCase(FindChar) << " is : "
		<< countNumberOfLetters(inputString, FindChar, false) << endl;

	return 0;

}