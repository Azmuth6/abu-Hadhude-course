#include <iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void loadFileToVector(string filename, vector <string> & vFilecontent)
{
	fstream MyFile;
	MyFile.open(filename, ios::in); //read

	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			vFilecontent.push_back(line);
		}
	}
	MyFile.close();
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

void PrintFileContent(string filename)
{
	fstream MyFile;
	MyFile.open(filename, ios::in);

	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			cout << line << endl;
		}
	}
	MyFile.close();
}

void DeleteContentFromFile(string filename , string record)
{
	vector <string> vFilecontent;

	loadFileToVector(filename, vFilecontent);

	for (string& line : vFilecontent)
	{
		if(line==record)
		{
			line = "";
		}
	}

	saveVectorToFile(filename, vFilecontent);
}

int main()
{
	cout << "file content is :- " << endl;
	PrintFileContent("Myfile.txt");

	DeleteContentFromFile("Myfile.txt", "nada");

	cout << "\n\nfile content after delete is :- " << endl;

	PrintFileContent("Myfile.txt");

	return 0;

}