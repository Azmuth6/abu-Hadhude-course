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

stClient Read()
{
    stClient client;
    cout << "Enter Account Number? ";
    getline(cin, client.AccountNumber);

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

string Print(stClient client, string Seperator)
{
    string stClientRecord = "";

    stClientRecord += client.AccountNumber + Seperator;
    stClientRecord += client.PinCode + Seperator;
    stClientRecord += client.Name + Seperator;
    stClientRecord += client.Phone + Seperator;
    stClientRecord += to_string(client.AccountBalance);

    return stClientRecord;

}

int main()
{
    cout << "\nPlease Enter Client Data: \n\n";
    stClient client;
    client = Read();

    cout << "\n\nClient Record for Saving is : \n"
        << Print(client, "#//#");

    return 0;

}