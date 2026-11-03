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

string LowLettersOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
            S1[i] = tolower(S1[i]);
    }
    return S1;
}

string UppLettersOfEachWord(string S1)
{
    bool isFirstLetter = true;
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = toupper(S1[i]);
    }
    return S1;
}

int main()
{
    string S = readString();
    string UPP = UppLettersOfEachWord(S);
    string LOW = LowLettersOfEachWord(S);

    cout << "LOW \n" << LOW;
    cout << "\nUPP \n" << UPP;

    system("pause>0");
}