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

string JoinString(string arr[], int length, string Limit)
{
	string S = "";
	for (int i = 0; i < length; i++)
	{
		S = S + arr[i] + Limit;
	}
	return S.substr(0, S.length() - Limit.length());
}


int main()
{
	string arr[] = { "Mohamed","Omar" , "fadi", "Ahmed" };
	vector <string> S1 = { "Mohamed","Omar" , "fadi", "Ahmed" };

	cout << "Vector string after Join : \n";
	cout << JoinString(S1, " , ");

	cout << "\n\nArray string after Join : \n";
	cout << JoinString(arr, 4, " , ");

	system("pause>0");
}