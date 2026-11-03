#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream Myfile;
	Myfile.open("Myfile", ios::out);
	if (Myfile.is_open())
	{
		Myfile << "hellow\n";
		Myfile << "1\n";
		Myfile << "2\n";
		
		cout << "DONE\n\n";

		Myfile.close();
	}
	return 0;
}
