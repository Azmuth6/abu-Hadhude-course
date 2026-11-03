#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector <int> vNumber;

	vNumber.push_back(10);
	vNumber.push_back(20);
	vNumber.push_back(30);
	vNumber.push_back(40);
	vNumber.push_back(50);

	cout << "First Number : " << vNumber.front() << endl ;
	cout << "Last Number  : " << vNumber.back() << endl;

	//returns the number of elements present in the vector
	cout << "Size         : " << vNumber.size() << endl;

	//check the overall size of a vector
	cout << "Capacity     : " << vNumber.capacity() << endl;

	//returns 1 (true) if the vector is empty
	cout << "Empthy       : " << vNumber.empty() << endl;

	cout << "YOUR NUMBER IS : \n";
	for (int& Num : vNumber)
	{
		cout << Num << " ";
	}
	
	cout << "\n\nI WILL REMOVE THE LAST NUMBER \n\n";
	vNumber.pop_back();
	cout << "THEN YOUR LAST NUMBER AFTER REMOVE IS : " << vNumber.back();
	
	
	cout << "\n\nI WILL REMOVE ALL NUMBERS \n\n";
	vNumber.clear();
	cout << "size         : " << vNumber.size() << "\n\n\n";

	

}
