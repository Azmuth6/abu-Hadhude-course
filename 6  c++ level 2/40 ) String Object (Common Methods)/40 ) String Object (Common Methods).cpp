#include <iostream>
#include <string>

using namespace std;

int main()
{

	string S1;
	S1 = "I Love Nadieen very much";

	cout << "Length of S1 is : " << S1.length() << endl << endl;

	cout << "The letter in endex 7 is : " << S1.at(7) << endl << endl;

	cout << "I will add in the end \" i want to marry\". : " << S1.append(" i want to marry") << endl << endl;

	cout << "I will add \" Dena\" at endex 6 : " << S1.insert(6, " Dena") << endl << endl;

	cout << "I will Prints all the next 4 letters from position 7 : " << S1.substr(7, 4) << endl << endl;

	S1.push_back('f');
	cout << "I will add \'f\' at the end : " << S1 << endl << endl;

	S1.pop_back();
	cout << "I will remove \'f\' at the end : " << S1 << endl << endl;

	cout << "The start of Dena at pos : " << S1.find("Dena") << endl;

	cout << S1.find("dena") << endl << endl;

	if (S1.find("dena") == S1.npos)
	{
		cout << "dena not foun" << endl << endl;
	}

	S1.clear();
	cout << S1 << endl << endl;

	return 0;
}
