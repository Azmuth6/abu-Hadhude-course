#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	cout << "\nYou entered: " << str << endl ;
	return str;
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

string ReverseWords(string S1)
{
	vector <string> vSplit;
	string S2 = "";
	vSplit = SplitEachWordsInString(S1, " ");

	vector <string>::iterator itr = vSplit.end();
	while (itr != vSplit.begin())
	{
		itr--;
		S2 += *itr + " ";

	}

	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}


int main()
{
	string Read = ReadString();

	string Reversed = ReverseWords(Read);
	cout << "\nReversed string: " << Reversed << endl;
	return 0;
	system("pause>0");
}