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

void printFirstLetterOfEachWord(string S1)
{
	bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            cout << S1[i] << endl;

        isFirstLetter = (S1[i] == ' ' ? true : false);
	}
}

int main()
{
	printFirstLetterOfEachWord(readString()); 
	return 0;


}