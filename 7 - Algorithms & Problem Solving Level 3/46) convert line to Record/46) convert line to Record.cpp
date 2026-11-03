#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};


vector <string> vSplite(string S1, string Delim)
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

stClient ConvertFromLineToRecord(string Line, string Seperator)
{
    stClient client;
    vector<string> vString;

    vString = vSplite(Line, Seperator);

    client.AccountNumber = vString[0];
    client.PinCode = vString[1];
    client.Name = vString[2];
    client.Phone = vString[3];
    client.AccountBalance = stod(vString[4]);

    return client;
}




void PrintClientRecord(stClient client)
{
    cout << "\nAccount Number : "
        << client.AccountNumber << endl;

    cout << "PinCode : "
    << client.PinCode << endl;

    cout << "Name : "
        << client.Name << endl;

    cout << "Phone : "
    << client.Phone << endl;

    cout << "AccountBalance : "
        << client.AccountBalance << endl;

    
}



int main()
{
    string stLine = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";  
    stClient client;

    cout << "\nLine Record is:\n";  
    cout << stLine << endl;

    client = ConvertFromLineToRecord(stLine, "#//#");

    PrintClientRecord(client);

    return 0;

}