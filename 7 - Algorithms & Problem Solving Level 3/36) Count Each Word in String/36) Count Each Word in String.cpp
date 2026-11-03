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


int CountEachWordsInString(string S1)
{
	int count = 0;
	short pos;
	string Limit = " ";
	string SWord;

	while ((pos = S1.find(Limit)) != std::string::npos)
	{
		SWord = S1.substr(0, pos);
		
		if (SWord != "")
			count++;


		S1.erase(0, pos + Limit.length());

	}

	if (S1 != "")
	{
		count++;
	}

	return count;

}

int main()
{
	int NumOfWordsInString = CountEachWordsInString(ReadString());

	cout << "Number of Words Is : " << NumOfWordsInString << endl;

	system("pause>0");

}