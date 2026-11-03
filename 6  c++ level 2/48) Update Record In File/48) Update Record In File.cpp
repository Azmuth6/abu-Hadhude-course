#include <iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void loadFileToVector(string filename, vector <string>& vFilecontent)
{
	fstream Myfile;
	Myfile.open(filename, ios::in);
	if (Myfile.is_open())
	{
		string line;
		while (getline(Myfile, line))
		{
			vFilecontent.push_back(line);
		}

		Myfile.close();
	}

}

void saveVectorToFile(string filename, vector <string> vFilecontent)
{
		fstream MyFile;
		MyFile.open(filename, ios::out);//write

		if (MyFile.is_open())
		{
			for (string& line : vFilecontent)
			{
				if (line != "")
				{
					MyFile << line << endl;
				}
			}
		}
		MyFile.close();
}


void printfilecontent(string filename)
{
	fstream Myfile;
	Myfile.open(filename, ios::in);
	if (Myfile.is_open())
	{
		string line;
		while (getline(Myfile, line))
		{
			cout << line << endl;
		}

		Myfile.close();
	}
}


void ChangeFileContent(string filename, string record , string ChangeUpTo)
{
	vector <string> vFileContent;
	loadFileToVector(filename, vFileContent);

	for (string& line: vFileContent)
	{
		if (line == record)
			line = ChangeUpTo;
	}

	saveVectorToFile(filename, vFileContent);
}


int main()
{
	cout << "file content is :- " << endl;
	printfilecontent("Myfile.txt");

	ChangeFileContent("Myfile.txt", "nada" , "dalia");

	cout << "\n\nfile content after Change is :- " << endl;

	printfilecontent("Myfile.txt");

	return 0;

}