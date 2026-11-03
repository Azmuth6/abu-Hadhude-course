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
int CountCapitalLetters(string str)
{

	int count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
		{
			count++;
		}
	}
	return count;
	
}
int CountSmallLetters(string str)
{

	int count = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (islower(str[i]))
		{
			count++;
		}
	}
	return count;

}

int main()
{
	string inputString = ReadString();
	 
	cout << "string Length: " << inputString.length() << endl;
	cout << "Number of capital letters: " << CountCapitalLetters(inputString) << endl;
	cout << "Number of small letters: " << CountSmallLetters(inputString) << endl;

	return 0;

}

/*

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return S1.length(); // طول النص كله
	}

	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			Counter++;

		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			Counter++;
	}

	return Counter;
}

int main()
{
	string text = "Hello World";

	cout << "All letters: " << CountLetters(text, enWhatToCount::All) << endl;
	cout << "Capital letters: " << CountLetters(text, enWhatToCount::CapitalLetters) << endl;
	cout << "Small letters: " << CountLetters(text, enWhatToCount::SmallLetters) << endl;

	return 0;
}

*/

