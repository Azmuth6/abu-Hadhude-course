#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

vector <string> SplitString(string S1, string Delim = "/")
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

string DateToString(stDate Date, string Separator = "/")
{
    string stClientRecord = "";

    stClientRecord += to_string(Date.Day) + Separator;
    stClientRecord += to_string(Date.Month) + Separator;
    stClientRecord += to_string(Date.Year);

    return stClientRecord;
}

string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    short pos = S1.find(StringToReplace);


    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);  //find next.
    }

    return S1;

}

stDate StringToDate(string Line, string Separator = "/")
{
    stDate Date;
    vector<string> vString;

    vString = SplitString(Line, Separator);

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

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = DateFormat;

    FormattedDateString = ReplaceWordInString(FormattedDateString, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;

}

int main()
{
    stDate Date;
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy ? ");

    Date = StringToDate(DateString);


    cout << "\n" << FormatDate(Date) << "\n"; 
    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n"; 
    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;

}