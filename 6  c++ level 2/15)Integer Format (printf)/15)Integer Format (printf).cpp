#include <iostream>
using namespace std;


int main()
{
	int page = 1 , totalPages = 10;

	printf("your page is %d \n", page);
	printf("your page is %d of %d \n\n", page, totalPages);

	printf("your page number = %0*d \n", 1, page);
	printf("your page number = %0*d \n", 2, page);
	printf("your page number = %0*d \n", 3, page);
	printf("your page number = %0*d \n\n", 4, page);


	int number1 = 20, number2 = 30;
	printf("sum of %d + %d = %d \n\n", number1, number2, number1 + number2);

	int n = 12;
	printf("your n is %0*2d \n", n);
	printf("your n is %3d \n", n);
	printf("your n is %4d \n", n);
	printf("your n is %5d \n", n);

	return 0;
}

