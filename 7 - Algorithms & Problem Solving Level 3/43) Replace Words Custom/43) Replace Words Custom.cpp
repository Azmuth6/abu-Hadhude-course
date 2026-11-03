#include <iostream>
#include <string>
#include <vector>

using namespace std;

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



string MakeAllLower(string S1) 
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& i : vString)
	{
		S1 = S1 + i + Delim;
	}

	return S1.substr(0, S1.length() - 1);
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string ReplaceTo, bool matchCases = true)
{
	vector <string> vSplit;
	vSplit = SplitEachWordsInString(S1, " ");

	for (string& i : vSplit)
	{
		if (matchCases)
		{
			if (i == StringToReplace)
			{
				i = ReplaceTo;
			}
		}
		
		else
		{
			
			if (MakeAllLower(i) == MakeAllLower(StringToReplace))
			{
				i = ReplaceTo;
			}

		}
	}
	
	return JoinString(vSplit, " ");
		
}



int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";

	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo);

	cout << "\n\nReplace with don't match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo, false) << endl;

	system("pause>0");
}