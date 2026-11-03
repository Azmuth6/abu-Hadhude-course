

#include <iostream>
#include"readNumber.h"
#include "Sum.h"

using namespace std;
using namespace Read;
using namespace Sum;

int main()
{
	 int num1 = ReadNumber();
	 int num2 = ReadNumber();

	 int sum = add(num1, num2);

	 cout << "sum of two numm is : >  " << sum << endl;
}

/*
#include <iostream>
#include"readNumber.h"
#include "Sum.h"

using namespace std;
int main()
{
	 int num1 = Read::ReadNumber();
	 int num2 = Read::ReadNumber();

	 int sum = Sum::add(num1, num2);

	 cout << "sum of two numm is : >  " << sum << endl;
}


*/