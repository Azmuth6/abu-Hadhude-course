#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vNumber = {10 , 20 , 30 , 40 , 50 };

	for (int& Number : vNumber) 
    // Using reference & to avoid copying and have higher performance , safty and speed
    {
		Number += 5;
        cout << Number << "  ";
    }

	return 0;   
}

