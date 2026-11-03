#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

stClient Read()
{
    stClient client;
    cout << "Enter Account Number? ";
    getline(cin >> ws, client.AccountNumber);

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

void ConvertToFile(string FileName, string Data)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << Data << endl;
        MyFile.close();
    }

}

void addNewClient()
{
    stClient client;
    client = Read();
    ConvertToFile(ClientsFileName, ConvertRecordToLine(client, "#//#"));
}


void NewClient()
{
    char addMore = 'Y';

    do
    {
        system("cls");
        cout << "Adding New Client : \n\n";
        addNewClient();

        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');


}


int main()
{
    NewClient();
    

    return 0;

}