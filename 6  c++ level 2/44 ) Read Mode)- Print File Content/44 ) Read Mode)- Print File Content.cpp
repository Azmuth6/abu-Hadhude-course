#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFromFile(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	
	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))
		{
			cout << line << endl;
		}

		MyFile.close();

	}

   
}

int main()
{
	PrintFromFile("Myfile.txt");
	return 0;
}