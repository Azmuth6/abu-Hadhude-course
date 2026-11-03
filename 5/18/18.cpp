#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string Text;  
    
    cout << "Please enter Text?\n"; 
    getline(cin, Text);             
    
    return Text;
}

string EncryptText(string Text, short EncryptionKey)
{
   
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
   
    for (int i = 0; i <= Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);
    }
    return Text;
}

int main ()
{
    string Text = ReadText();
    short EncryptionKey = 3;
    string Text_After_Encryption, Text_After_Decryption;

    Text_After_Encryption = EncryptText(Text, EncryptionKey);

    Text_After_Decryption = DecryptText(Text_After_Encryption, EncryptionKey);

    cout << "\nText Before Encryption : " << Text << endl;
    cout << "Text After Encryption  : " << Text_After_Encryption << endl;
    cout << "Text After Decryption  : " << Text_After_Decryption << endl;


    return 0;


}