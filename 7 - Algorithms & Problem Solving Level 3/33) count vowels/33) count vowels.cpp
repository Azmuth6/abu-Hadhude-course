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

int vowelsCheck(string str)
{
	
	char vowles[5] = { 'a','i','o','u','e' };

	int count = 0;

	for (short i = 0; i < str.length(); i++)
	{
		for (short j = 0; j < 5 ; j++)
		{
			if (tolower(str[i]) == vowles[j])
			{
				count++;
			}
		}
	}
	return count;
}



int main()
{

	string FindString = ReadString();

	cout << "Number of Vowels in the String : " << vowelsCheck(FindString) << endl;
	
	return 0;

}