#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Enums
enum enTransactionsMenueOptions {
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eShowTotalBalance = 4,
    eLogOut = 5
};

// Constants
const string ClientsFileName = "Clients.txt";

// Structures
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// Global Variables
sClient CurrentUser;

// Forward Declarations
void ShowAtmMenue();
void GoBackToMainMenue();
void Login();

// Input Functions
short ReadAtmMenueOption()
{
    cout << "\nChoose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

short ReadQuickWithdrawOption()
{
    cout << "\nChoose what do you want to do? [1 to 9]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

int ReadWithDrawAmont()
{
    int Amount;
    cout << "\nEnter an amount multiple of 5's ? ";

    cin >> Amount;

    while (Amount % 5 != 0)
    {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> Amount;
    }
    return Amount;
}

// String Processing Functions
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

// Data Conversion Functions
sClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Separator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double

    return Client;
}

string ConvertRecordToLine(sClient Client, string Separator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

// File Operations
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

// Authentication Functions
bool FindUserByUsernameAndPassword(string AccountNumber, string PinCode, sClient& Client)
{
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

bool LoadUserInfo(string AccountNumber, string PinCode)
{
    if (FindUserByUsernameAndPassword(AccountNumber, PinCode, CurrentUser))
        return true;
    else
        return false;
}

void Login()
{
    bool LoginFaild = false;

    string AccountNumber, PinCode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invalid Account Number / Pin Code!\n";
        }

        cout << "Enter AccountNumber? ";
        cin >> AccountNumber;

        cout << "Enter PinCode? ";
        cin >> PinCode;

        LoginFaild = !LoadUserInfo(AccountNumber, PinCode);

    } while (LoginFaild);

    ShowAtmMenue();
}

// Display Functions
void ShowTotalBalances()
{
    cout << "Total Balances = " << CurrentUser.AccountBalance;
}

void ShowNumberForQuickWithDrawScreen()
{
    cout << "\t\t[1] 20  \t\t [2] 50 \n";
    cout << "\t\t[3] 100 \t\t [4] 200 \n";
    cout << "\t\t[5] 400 \t\t [6] 600 \n";
    cout << "\t\t[7] 800 \t\t [8] 1000\n";
    cout << "\t\t[9] Exit  \n";
}

// Transaction Functions
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                CurrentUser.AccountBalance = C.AccountBalance;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                return true;
            }
        }
        return false;
    }
    return false;
}

// Quick Withdraw Functions
void QuickWithDrawBySwitch() {
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    int Option = ReadQuickWithdrawOption();
    double Amount = 0;

    switch (Option) {
    case 1: Amount = 20; break;
    case 2: Amount = 50; break;
    case 3: Amount = 100; break;
    case 4: Amount = 200; break;
    case 5: Amount = 400; break;
    case 6: Amount = 600; break;
    case 7: Amount = 800; break;
    case 8: Amount = 1000; break;
    case 9: ShowAtmMenue(); return;
    default: cout << "Invalid option!\n"; return;
    }

    if (Amount > CurrentUser.AccountBalance) {
        cout << "\nAmount exceeds the balance, you can withdraw up to: " << CurrentUser.AccountBalance << endl;
        GoBackToMainMenue();
        return;
    }

    DepositBalanceToClientByAccountNumber(CurrentUser.AccountNumber, -Amount, vClients);

    ShowTotalBalances();
}

// Screen Functions
void ShowQuickWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tQuick Withdraw Screen";
    cout << "\n-----------------------------------\n";

    ShowNumberForQuickWithDrawScreen();

    ShowTotalBalances();

    QuickWithDrawBySwitch();

    GoBackToMainMenue();
}

void ShowNormalWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tNormal Withdraw Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    int Amount = 0;

    ShowTotalBalances();

    int WithDrawBalance = ReadWithDrawAmont();

    if (WithDrawBalance > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Anykey to continue...";
        system("pause>0");
        ShowNormalWithDrawScreen();
        return;
    }

    while (Amount > CurrentUser.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << CurrentUser.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(CurrentUser.AccountNumber, Amount * -1, vClients);
    ShowTotalBalances();

    GoBackToMainMenue();
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    ShowTotalBalances();

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(CurrentUser.AccountNumber, Amount, vClients);
    ShowTotalBalances();

    GoBackToMainMenue();
}

void ShowTotalBalanceScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tTotal Balance";
    cout << "\n-----------------------------------\n";

    ShowTotalBalances();

    GoBackToMainMenue();
}

// Menu Functions
void PerfromAtmMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eQuickWithdraw:
    {
        system("cls");
        ShowQuickWithDrawScreen();
        break;
    }

    case enTransactionsMenueOptions::eNormalWithdraw:
    {
        system("cls");
        ShowNormalWithDrawScreen();
        break;
    }

    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        break;
    }

    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalanceScreen();
        break;
    }

    case enTransactionsMenueOptions::eLogOut:
    {
        Login();
    }
    }
}

void ShowAtmMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Menu Screen\n";
    cout << "===========================================\n";

    cout << "\nWelcome, " << CurrentUser.Name << "!\n\n";

    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Show Total Balance.\n";
    cout << "\t[5] Log Out.\n";
    cout << "===========================================\n";
    PerfromAtmMenueOption((enTransactionsMenueOptions)ReadAtmMenueOption());
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowAtmMenue();
}

// Main Function
int main()
{
    Login();
}