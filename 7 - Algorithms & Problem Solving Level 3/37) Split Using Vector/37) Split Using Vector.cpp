#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string input;
	cout << "Enter String you Want to Check : ";
	getline(cin, input);
	return input;
}


vector <string> SplitEachWordsInString(string S1, string Limit)
{
	short pos;
	string SWord;
	vector <string> sSplit;

	while ((pos = S1.find(Limit)) != std::string::npos)
	{
		SWord = S1.substr(0, pos);

		if (SWord != "")
		{
			sSplit.push_back(SWord);
		}


		S1.erase(0, pos + Limit.length());

	}

	if (S1 != "")
	{
		sSplit.push_back(S1);
	}

	return sSplit;

}

void print(vector <string> sSplit)
{
	for (string& i : sSplit)
	{
		cout << i << endl;
	}
}

int main()
{
	int count = 0;
	vector <string> sSplit;
	string Read = ReadString();

	sSplit = SplitEachWordsInString(Read, " ");

	cout << "Number of Words Is : " << sSplit.size() << endl;

	print(sSplit);


	system("pause>0");

}