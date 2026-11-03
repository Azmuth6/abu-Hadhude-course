#include <iostream>
#include <string>
#include <cstdlib>    
#include <ctime>      
using namespace std;

int Random_Number (int from , int to)
{
   
    int random = rand() % (to - from +1 ) + from ;
    return random ;

}

enum CharacterType {smallLetter = 1, capitalLetter =2, digit = 3, specialCharacter = 4};

char Random_Character (CharacterType type)
{
    char randomChar;
    switch (type)
    {
        case smallLetter:
            randomChar = char(Random_Number(97, 122)); 
            break;
        case capitalLetter:
            randomChar = char(Random_Number(65, 90)); 
            break;
        case digit:
            randomChar = char(Random_Number(48, 57)); 
            break;
        case specialCharacter:
            randomChar = char(Random_Number(33, 47)); 
            break;
        default:
            randomChar = ' '; 
    }
    return randomChar;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0; 
    do
    {
        cout << Message ;
        cin >> Number;          
    } while (Number <= 0);      
    return Number;
}

string GenerateWord (CharacterType type , short length  )
{
        string Word;  

   
    for (int i = 1; i <= length; i++)
    {
        
        Word = Word + Random_Character(type);
    }
    return Word;

}

string GenerateKey ()
{

    string key ;
    
    key = GenerateWord(CharacterType::capitalLetter , 4) + "-" ;
    key = key + GenerateWord(CharacterType::capitalLetter , 4) + "-" ;
    key =  key + GenerateWord(CharacterType::capitalLetter , 4) + "-" ;
    key = key + GenerateWord(CharacterType::capitalLetter , 4)  ;

    return key ;

}

void key (short NUmOfKeys)
{
    
        for (int i = 1; i <= NUmOfKeys; i++)
    {
       
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }


}


int main () 
{
     srand((unsigned)time(NULL));
    key(ReadPositiveNumber("enter num of keys : ") );

    
    return 0 ;


}
