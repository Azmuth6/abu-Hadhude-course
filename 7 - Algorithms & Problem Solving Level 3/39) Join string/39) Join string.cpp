#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector <string> vString, string Limit)
{
	string S = "";
	for (string& i : vString)
	{
		S = S + i + Limit;
	}
	return S.substr(0, S.length() - Limit.length());
}

int main()
{
	vector <string> S1 = { "Mohamed","Omar" , "fadi", "Ahmed" };

	cout << "string after Join : \n";
	cout <<JoinString(S1, " , ");

	system("pause>0");
}