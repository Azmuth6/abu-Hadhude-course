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

string ReadAccountNumber()
{
    string AccountNumber = "";
    cout << "Enter Account Number For Search : ";
    cin >> AccountNumber;
    return AccountNumber;
}


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

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
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

string ConvertRecordToLine(stClient client, string Seperator)
{
    string stClientRecord = "";

    stClientRecord += client.AccountNumber + Seperator;
    stClientRecord += client.PinCode + Seperator;
    stClientRecord += client.Name + Seperator;
    stClientRecord += client.Phone + Seperator;
    stClientRecord += to_string(client.AccountBalance);

    return stClientRecord;
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
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(stClient client)
{
    cout << "\nAccount Number   : " << client.AccountNumber;
    cout << "\nPinCode          : " << client.PinCode;
    cout << "\nName             : " << client.Name;
    cout << "\nPhone            : " << client.Phone;
    cout << "\nAccountBalance   : " << client.AccountBalance;
}

bool FindClient(string AccountNumber, vector<stClient> vClients, stClient& Client)
{
    for (stClient& STCLIENT : vClients)
    {
        if (AccountNumber == STCLIENT.AccountNumber)
        {
            Client = STCLIENT;
            return true;
        }
    }
    return false;
}

stClient Read(string AccountNumber)
{
    stClient client;
    client.AccountNumber = AccountNumber;
    cout << "\nEnter PinCode? ";
    getline(cin >> ws, client.PinCode);

    cout << "Enter Name? ";
    getline(cin, client.Name);

    cout << "Enter Phone? ";
    getline(cin, client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> client.AccountBalance;

    return client;
}


void SaveClientsDataToFile(string filename, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(filename, ios::out);

    if (MyFile.is_open())
    {
        for (stClient& ST : vClients)
        {
                MyFile << ConvertRecordToLine(ST, "#//#") << endl;
            
        }
        MyFile.close();
    }
}

bool ChangeClientInfoByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClient(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to change this client? y/n ? ";
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            for (stClient& ST : vClients)
            {
                if (ST.AccountNumber == AccountNumber)
                {
                    ST = Read(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Changed Successfully.";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}

int main()
{
    string AccountNumber = ReadAccountNumber();
    vector <stClient> vClients;
    vClients = RestoreFromFile(ClientsFileName);

    ChangeClientInfoByAccountNumber(AccountNumber, vClients);

    return 0;
}