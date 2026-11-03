#include <iostream>
#include <string>
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.
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
            randomChar = '  '; 
    }
    return randomChar;
}

int main ()
{
     
        srand( (unsigned) time (NULL) ) ; 

       cout << Random_Character(CharacterType::smallLetter) << endl ;
       cout << Random_Character(CharacterType::capitalLetter) << endl ;
       cout << Random_Character(CharacterType::digit) << endl ;
       cout << Random_Character(CharacterType::specialCharacter) << endl ;

    return 0;

}