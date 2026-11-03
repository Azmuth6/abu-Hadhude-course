#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

string ReadAccountNumber()
{
    string AccountNumber = "";
    cout << "Enter Account Number For Search : ";
    cin >> AccountNumber;
    return AccountNumber;
}

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

stClient ConvertFromLineToRecord(string Line, string Seperator = "#//#")
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

vector <stClient> RestoreFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        stClient Client;
        string Line;

        while (getline(MyFile, Line))
        {
            Client = ConvertFromLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }
    return vClients;
}

void PrintFound(stClient client)
{
    cout << "\nAccount Number   : " << client.AccountNumber << endl;

    cout << "PinCode          : " << client.PinCode << endl;

    cout << "Name             : " << client.Name << endl;

    cout << "Phone            : " << client.Phone << endl;

    cout << "AccountBalance   : " << client.AccountBalance << endl;
}

bool FindClient(string AccNum, stClient& Client)
{
    vector<stClient> vClients;
    vClients = RestoreFromFile(ClientsFileName);

    for (stClient &STCLIENT : vClients)
    {
        if (AccNum == STCLIENT.AccountNumber)
        {
            Client = STCLIENT;
            return true;
        }
    }

    return false;
}


int main()
{
    string AccNumber = ReadAccountNumber();
    stClient Client;

    if (FindClient(AccNumber, Client))
    {
        PrintFound(Client);
    }
    else
        cout << "\nAccount Number (" << AccNumber << ") NotFound\n";


}