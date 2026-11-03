#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char x;
	char y;

	x = toupper('n');
	y = tolower('N');

	cout << "converting n to N: " << x << endl;
	cout << "converting N to n: " << y << endl;

	cout << "isupper('N') " << isupper('N') << endl;

	cout << "islower('n') " << islower('n') << endl;

	cout << "isdigit('4') " << isdigit('4') << endl;

	// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	// returns zero if not, and non zero of yes

	cout << "ispunct(;) " << ispunct(';') << endl;

	return 0;
}
