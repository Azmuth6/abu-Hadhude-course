#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string filename, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(filename, ios::in);
	
	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			vFileContent.push_back(line);
		}

		MyFile.close();
	}
}

int main()
{
	vector <string> vFileContent;
	LoadDataFromFileToVector("Myfile.txt", vFileContent);

	for (string& line : vFileContent)
	{
		cout << line << endl;
	}
	
	return 0;

}

