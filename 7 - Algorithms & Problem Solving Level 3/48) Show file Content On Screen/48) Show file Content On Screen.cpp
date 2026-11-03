#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

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

void PrintClientRecord(stClient client)
{
    cout << "|" << setw(15) << left << client.AccountNumber;
    cout << "|" << setw(10) << left << client.PinCode;
    cout << "|" << setw(40) << left << client.Name;
    cout << "|" << setw(12) << left << client.Phone;
    cout << "|" << setw(12) << left << client.AccountBalance;

}

void Print(vector<stClient> vClients)
{
    cout << "\t\t\t\t\t clients list (" << vClients.size() << ") " << endl;

    cout << "\n---------------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(15) << left << "AccountNumber";
    cout << "|" << setw(10) << left << "PinCode";
    cout << "|" << setw(40) << left << "Name";
    cout << "|" << setw(12) << left << "Phone";
    cout << "|" << setw(12) << left << "AccountBalance";
    cout << "\n---------------------------------------------------------------------------------------------------\n";

    for (stClient STCLIENT : vClients)
    {
        PrintClientRecord(STCLIENT);
        cout << endl;
    }
    cout << "\n---------------------------------------------------------------------------------------------------\n";

}

int main()
{
    vector<stClient> vClients;
    vClients = RestoreFromFile(ClientsFileName);
    Print(vClients);

    return 0;

}