#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// تعريفات وثوابت
const string ClientsFileName = "Clients.txt";

enum enTransactionsMenueOptions
{
    eDeposit = 1, eWithdraw = 2, eTotalBalance = 3,
    eMainMenu = 4
};

enum enMainMenueOptions
{
    eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eExit = 7
};

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

void GoBackToMainMenue();
void GoBackToTransactionsMenue();

void ShowMainMenue();
void ShowTransactionMenu();

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption);
void PerfromTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption);

bool CheckByAccountNumber(stClient Client, vector<stClient>& vString);

// دوال القراءة والتحويل
string ReadAccountNumber()
{
    string AccountNumber = "";
    cout << "Enter Account Number For Search : ";
    cin >> AccountNumber;
    return AccountNumber;
}

stClient ReadClientsInfoByAccountNumber(string AccountNumber)
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

stClient ReadAllClientData(vector<stClient>& vString)
{
    stClient client;
    do
    {
        cout << "\nEnter Account Number? ";
        getline(cin >> ws, client.AccountNumber);
        if (CheckByAccountNumber(client, vString))
            cout << "this Account Number is already taken";
    } while (CheckByAccountNumber(client, vString));
    cout << "Enter PinCode? ";
    getline(cin, client.PinCode);
    cout << "Enter Name? ";
    getline(cin, client.Name);
    cout << "Enter Phone? ";
    getline(cin, client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> client.AccountBalance;
    return client;
}

vector<string> vSplite(string S1, string Delime = "#//#")
{
    int pos = 0;
    vector<string> vClient;
    string sWord;
    while ((pos = S1.find(Delime)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
            vClient.push_back(sWord);
        S1.erase(0, pos + Delime.length());
    }
    if (S1 != "")
        vClient.push_back(S1);
    return vClient;
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

// دوال التعامل مع الملفات
vector<stClient> RestoreFromFile(string FileName)
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

void SaveClientsDataToFile(string filename, vector<stClient>& vClients)
{
    fstream MyFile;
    MyFile.open(filename, ios::out);
    if (MyFile.is_open())
    {
        for (stClient& ST : vClients)
        {
            if (ST.MarkForDelete == false)
            {
                MyFile << ConvertRecordToLine(ST, "#//#") << endl;
            }
        }
        MyFile.close();
    }
}

// دوال البحث والتحقق
bool FindClient(string& AccountNumber, vector<stClient>& vClients, stClient& Client)
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

bool CheckByAccountNumber(stClient Client, vector<stClient>& vString)
{
    for (stClient& i : vString)
    {
        if (Client.AccountNumber == i.AccountNumber)
            return true;
    }
    return false;
}

bool MarkClientForDelete(string AccountNumber, vector<stClient>& vClients)
{
    for (stClient& STCLIENT : vClients)
    {
        if (AccountNumber == STCLIENT.AccountNumber)
        {
            STCLIENT.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

// دوال العرض
void PrintClientCard(stClient client)
{
    cout << "\nAccount Number   : " << client.AccountNumber;
    cout << "\nPinCode          : " << client.PinCode;
    cout << "\nName             : " << client.Name;
    cout << "\nPhone            : " << client.Phone;
    cout << "\nAccountBalance   : " << client.AccountBalance;
}

void PrintClientRecord(stClient client)
{
    cout << "|" << setw(15) << left << client.AccountNumber;
    cout << "|" << setw(10) << left << client.PinCode;
    cout << "|" << setw(40) << left << client.Name;
    cout << "|" << setw(12) << left << client.Phone;
    cout << "|" << setw(12) << left << client.AccountBalance;
}

void PrintClientRecordForBalance(stClient client, double& TotalBlance)
{
    cout << "|" << setw(15) << left << client.AccountNumber;
    cout << "|" << setw(40) << left << client.Name;
    cout << "|" << setw(12) << left << client.AccountBalance;
    TotalBlance += client.AccountBalance;
}

void PrintAllCliants()
{
    vector<stClient> vClients;
    vClients = RestoreFromFile(ClientsFileName);
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

void PrintAllCliantsForBalance()
{
    double TotalBlance = 0;
    vector<stClient> vClients;
    vClients = RestoreFromFile(ClientsFileName);
    cout << "\t\t\t\t\t clients list (" << vClients.size() << ") " << endl;
    cout << "\n---------------------------------------------------------------------------------------------------\n";
    cout << "|" << setw(15) << left << "AccountNumber";
    cout << "|" << setw(40) << left << "Name";
    cout << "|" << setw(12) << left << "AccountBalance";
    cout << "\n---------------------------------------------------------------------------------------------------\n";
    for (stClient STCLIENT : vClients)
    {
        PrintClientRecordForBalance(STCLIENT, TotalBlance);
        cout << endl;
    }
    cout << "Total Balance : " << TotalBlance << endl;
    cout << "\n---------------------------------------------------------------------------------------------------\n";
}

// دوال الإجراءات
int ReadNumber()
{
    int Number;
    cout << "Enter Number : ";
    cin >> Number;
    return Number;
}

void Deposit(stClient& Client)
{
    int Number = ReadNumber();
    Client.AccountBalance = Client.AccountBalance + Number;
    cout << "Account Balance Now is : " << Client.AccountBalance;
}

void Withdraw(stClient& Client)
{
    int Number = ReadNumber();
    while (Client.AccountBalance < Number)
    {
        cout << "your Balance is not enough, enter smaller amount\n";
        Number = ReadNumber();
    }
    Client.AccountBalance = Client.AccountBalance - Number;
    cout << "Account Balance Now is : " << Client.AccountBalance;
}

bool AddNewClient()
{
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    char Answer = 'n';
    cout << "\n\nAre you sure you want to add New client? y/n ? ";
    cin >> Answer;
    if (tolower(Answer) == 'y')
    {
        stClient Client = ReadAllClientData(vClients);
        vClients.push_back(Client);
        SaveClientsDataToFile(ClientsFileName, vClients);
        cout << "\n\nClient added Successfully.";
        return true;
    }
    return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients)
{
    stClient Client;
    char Answer = 'n';
    if (FindClient(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want to delete this client? y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
        {
            MarkClientForDelete(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            vClients = RestoreFromFile(ClientsFileName);
            cout << "\n\nClient Deleted Successfully.";
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
                    ST = ReadClientsInfoByAccountNumber(AccountNumber);
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

// دوال القوائم
void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";
    AddNewClient();
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    ChangeClientInfoByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    stClient Client;
    string AccountNumber = ReadAccountNumber();
    if (FindClient(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    for (stClient& Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            PrintClientCard(Client);
            Deposit(Client);
            SaveClientsDataToFile(ClientsFileName, vClients);
            return;
        }
    }
    cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowWithdrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";
    vector<stClient> vClients = RestoreFromFile(ClientsFileName);
    string AccountNumber = ReadAccountNumber();
    for (stClient& Client : vClients)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            PrintClientCard(Client);
            Withdraw(Client);
            SaveClientsDataToFile(ClientsFileName, vClients);
            return;
        }
    }
    cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menu...";
    system("pause>0");
    ShowTransactionMenu();
}

void ShowTransactionMenu()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "===========================================\n";
    PerfromTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void PerfromTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
{
    switch (TransactionsMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }
    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsMenue();
        break;
    }
    case enTransactionsMenueOptions::eTotalBalance:
    {
        system("cls");
        PrintAllCliantsForBalance();
        GoBackToTransactionsMenue();
        break;
    }
    case enTransactionsMenueOptions::eMainMenu:
    {
        system("cls");
        ShowMainMenue();
        break;
    }
}
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        PrintAllCliants();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
    {
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eDeleteClient:
    {
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eUpdateClient:
    {
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eFindClient:
    {
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eTransactions:
    {
        system("cls");
        ShowTransactionMenu();
        break;
    }
    case enMainMenueOptions::eExit:
    {
        system("cls");
        ShowEndScreen();
        break;
    }
}
}

// الدالة الرئيسية
int main()
{
    ShowMainMenue();
    return 0;
}