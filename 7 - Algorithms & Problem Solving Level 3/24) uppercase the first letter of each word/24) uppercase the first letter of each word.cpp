#include <iostream>
#include <string>
using namespace std;

string readString()
{
    string Full;
    cout << "enter String\n";
    getline(cin, Full);

    return Full;
}

string UppFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
			S1[i] = toupper(S1[i]);

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}


int main()
{
    string str =  UppFirstLetterOfEachWord(readString());
	cout << "String after Uppercasing first letter of each word: \n" << str << endl;
    return 0;


}