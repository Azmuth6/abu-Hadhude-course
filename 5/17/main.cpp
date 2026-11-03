
#include <iostream>
#include <string>

using namespace std;

string ReadPassword()
{
        string password ;
        cout << "Please enter a 3-Letter Password (all capital)?\n";
        cin >> password;
    
    return password;
}

void printLetters(string origin_password)
{
    int trying = 1;
    string Guess_password = "";
    
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Guess_password += char(i) ;
                Guess_password += char(j) ;
                Guess_password += char(k) ;
                cout << "trying [" << trying << "] : " <<  Guess_password << endl;
                trying++;
                
                if (Guess_password == origin_password)
                {
                    cout << "\nPassword is " << Guess_password << "\n";
                    cout << "Found after " << trying << " Trial(s)\n";
                    return;
                }
                Guess_password = "";
            }
        }
    }
}

int main()
{
    printLetters(ReadPassword());
    return 0;
}
