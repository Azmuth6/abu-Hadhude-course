#pragma warning(disable : 4996) 

#include<ctime>
#include<iostream>

using namespace std;

int main()
{
	//time_t t = time(0); // get time now
	//
	//char* dt = ctime(&t);   // convert in string form
	//cout << "Local date and time is: " << dt << "\n";  
	
	//// converting now to tm struct for UTC date/time
	//
	// tm* gmtm = gmtime(&t); 
	// 
	// dt = asctime(gmtm); 
	// 
	// cout << "UTC date and time is: " << dt;


	time_t t = time(0);
	char* koko = ctime(&t);
	cout << "Local date and time is: " << koko << "\n";


	tm* kokogre = gmtime(&t);
	koko = asctime(kokogre);
	cout << "UTC date and time is: " << koko;

	 return 0;
} 