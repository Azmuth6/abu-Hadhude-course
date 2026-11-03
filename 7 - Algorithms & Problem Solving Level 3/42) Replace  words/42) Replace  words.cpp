#include <iostream>
#include <string>
#include <vector>

using namespace std;

//vector <string> SplitEachWordsInString(string S1, string Limit)
//{
//	short pos;
//	string SWord;
//	vector <string> sSplit;
//
//	while ((pos = S1.find(Limit)) != std::string::npos)
//	{
//		SWord = S1.substr(0, pos);
//
//		if (SWord != "")
//		{
//			sSplit.push_back(SWord);
//		}
//
//		S1.erase(0, pos + Limit.length());
//	}
//
//	if (S1 != "")
//	{
//		sSplit.push_back(S1);
//	}
//	return sSplit;
//}
//
//string ReplaceWords(string S1, string StringToReplace ,string ReplaceTo)
//{
//	vector <string> vSplit;
//	string S2 = "";
//	vSplit = SplitEachWordsInString(S1, " ");
//
//	for (string& i : vSplit)
//	{
//		if (i == StringToReplace)
//		{
//			S2 = S2 + ReplaceTo + " ";
//		}
//		else
//		{
//			S2 = S2 + i +" ";
//		}
//	}
//	S2 = S2.substr(0, S2.length() - 1);
//
//	return S2;
//}



string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
	short pos = S1.find(StringToReplace);


	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = S1.find(StringToReplace);  //find next
	}

	return S1;

}


int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string ReplaceTo = "USA";

	cout << "Word :\n" << S1;


	cout << "\nAfter  Change : \n" << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);
	
	system("pause>0");
}