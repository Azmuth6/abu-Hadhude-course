#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

vector <string> vSplit(string S1, string Delim = "/")
{
    int pos = 0;
    vector<string> vString;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
        vString.push_back(S1);

    return vString;

}

string ConvertRecordToLine(stDate Date, string Seperator = "/")
{
    string stClientRecord = "";

    stClientRecord += to_string(Date.Day) + Seperator;
    stClientRecord += to_string(Date.Month) + Seperator;
    stClientRecord += to_string(Date.Year);

    return stClientRecord;
}

stDate ConvertFromLineToRecord(string Line, string Seperator = "/")
{
    stDate Date;
    vector<string> vString;

    vString = vSplit(Line, Seperator);

    Date.Day = stoi(vString[0]);
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);
    

    return Date;
}


string ReadStringDate(string Message) 
{
    string DateString;
    cout << Message;
    
    getline(cin >> ws, DateString);
    
    return DateString;
}

int main()
{
    stDate Date;
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");

    Date = ConvertFromLineToRecord(DateString);


    cout << "\nDay:" << Date.Day << endl;
    cout << "Month:" << Date.Month << endl;
    cout << "Year:" << Date.Year << endl;

    cout << "\nYou Entered: " << ConvertRecordToLine(Date) << "\n";

    system("pause>0");
    return 0;

}