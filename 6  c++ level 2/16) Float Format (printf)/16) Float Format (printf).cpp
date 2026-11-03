#include <iostream>
using namespace std;

int main()
{
    float PI = 3.1415926535;

    printf("your float number = %.*f \n", 1, PI);
    printf("your float number = %.*f \n", 2, PI);
    printf("your float number = %.*f \n", 3, PI);
    printf("your float number = %.*f \n\n\n", 4, PI);

    float x = 7.0 , y = 9.0 ;
	printf("the float dvision result : %.3f / %.3f = %.3f \n\n\n", x, y, x / y);

    double a = 12.45;
	printf("the double number = %.2f \n", a);
    printf("the double number = %.3f \n", a);
    printf("the double number = %.4f \n", a);
    printf("the double number = %.5f \n\n\n", a);
    long double b = 123456789.123456789;
    printf("the long double number = %.2Lf \n", b);
    printf("the long double number = %.3Lf \n", b);
    printf("the long double number = %.4Lf \n", b);
    printf("the long double number = %.5Lf \n", b);
	return 0;




}