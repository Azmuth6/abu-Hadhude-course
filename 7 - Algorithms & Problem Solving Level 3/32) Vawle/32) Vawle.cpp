#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
	char input;
	cout << "Enter Char you Want to Check : ";
	cin >> input;
	return input;
}




bool vowelsCheck(char str)
{
	str = tolower(str);
	char vowles[5] = { 'a','i','o','u','e' };
	
	for (short i = 0; i <5 ; i++)
	{
		if (str == vowles[i])
		{
			return true;
		}
		else 
			return false;
	}
}



int main()
{
	
	char FindChar = ReadChar();

	if (vowelsCheck(FindChar))
	{
		cout << "The Char " << FindChar << " is a Vowel" << endl;
	}
	else
	{
		cout << "The Char " << FindChar << " is not a Vowel" << endl;
	}
	return 0;

}