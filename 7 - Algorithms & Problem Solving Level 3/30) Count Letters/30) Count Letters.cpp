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


int countNumberOfLetters(string str,char Record)
{

	int count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] == Record )
		{
			count++;
		}
	}
	return count;

}

int main()
{
	string inputString = ReadString();
	char FindChar = ReadFind();

	
	cout << "Number of letters you want to find : " << countNumberOfLetters(inputString, FindChar) << endl;

	return 0;

}