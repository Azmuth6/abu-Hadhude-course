#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream Myfile;
	Myfile.open("Myfile.txt", ios::out | ios::app);
	if (Myfile.is_open())
	{
		Myfile << "4444\n";
		Myfile << "555\n";
		Myfile << "66\n";

		cout << "DONE\n\n";

		Myfile.close();
	}
	return 0;
}
