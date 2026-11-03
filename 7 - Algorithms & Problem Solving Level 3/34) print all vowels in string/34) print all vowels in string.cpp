#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string input;
	cout << "Enter String you Want to Check : ";
	getline(cin, input);
	return input;
}

bool IsVowel(char Ch1) 
{
	Ch1 = tolower(Ch1);
	return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
}

int CountVowels(string S1) 
{
	int count = 0;
	for (char c : S1)
	{
		if (IsVowel(c))
			count++;
	}
	return count;
}

void PrintVowels(string S1) {
	cout << "\nVowels in string are: ";
	for (char c : S1) {
		if (IsVowel(c))
			cout << c << "    ";
	}
	cout << endl;
}



int main()
{
	string S1 = ReadString();

	PrintVowels(S1);

	cout << "\nTotal number of vowels = " << CountVowels(S1) << endl;

	system("pause>0");
	return 0;

}