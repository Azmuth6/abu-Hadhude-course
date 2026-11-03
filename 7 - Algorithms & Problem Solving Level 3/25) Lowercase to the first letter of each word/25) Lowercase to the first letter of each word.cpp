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

string LowFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
            S1[i] = tolower(S1[i]);

        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main()
{
    string str = LowFirstLetterOfEachWord(readString());
    cout << "String after Lowercasing first letter of each word: \n" << str << endl;

    system("pause>0");
}