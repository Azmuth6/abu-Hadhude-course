#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SaveVectorToFile(string filename, vector<string>vfilecontent)
{
	fstream MyFile;
	MyFile.open(filename, ios::out);

	if (MyFile.is_open())
	{
		for (string& line : vfilecontent)
		{
			if(line!="")
				MyFile << line << endl;
		}

		MyFile.close();
	}
}


int  main()
{
	vector <string> vfilecontent{ "Dena","Salma","Dai","Mai" };
	SaveVectorToFile("Myfile.txt", vfilecontent);
	return 0;
}