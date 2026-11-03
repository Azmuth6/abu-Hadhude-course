#include <iostream>
using namespace std;


int main()
{
	char  Name[] = "John Doe";
	char schoolName[] = "ABC University";


	printf("name : %s \n", Name);
	printf("school name : %s \n\n\n", schoolName);

	char c = 'A';

	printf("char : %*c \n", 1, c);
	printf("char : %*c \n", 2, c);
	printf("char : %*c \n", 3, c);
	printf("char : %*c \n", 4, c);

	return 0;

}

