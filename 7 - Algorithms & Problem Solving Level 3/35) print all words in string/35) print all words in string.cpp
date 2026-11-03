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

//void PrintWordsInString(string S1) {
//	cout << "\nWords in string are: \n";
//	for (char c : S1) {
//
//		cout << c;
//		if (c == ' ')
//			cout << endl;
//	}
//	cout << endl;
//}

void PrintWordsInStringWithSringFun(string S1)
{
	short pos = 0;
	string deline = " ";
	string SWord;
	 
	cout << "\nWords in string are: \n";

	while ((pos = S1.find(deline)) != std::string::npos) 
	{
		SWord = S1.substr(0, pos);
		
		if (SWord != " ")
			cout << SWord << endl;

		S1.erase(0, pos + deline.length());
	}

	if (S1 != " ")
	{
		cout << S1 << endl;
	}

}


int main()
{
	string S1 = ReadString();

	/*PrintWordsInString(S1);*/

	PrintWordsInStringWithSringFun(S1);

	system("pause>0");
	return 0;

}