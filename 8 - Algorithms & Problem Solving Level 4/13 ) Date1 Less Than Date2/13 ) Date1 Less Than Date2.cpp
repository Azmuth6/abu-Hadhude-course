#include <iostream>
#include <iomanip>

using namespace std;

short ReadYear()
{
	short Num;
	cout << "Enter Year : ";
	cin >> Num;
	return Num;
}
short ReadMonth()
{
	short Num;
	cout << "Enter Month : ";
	cin >> Num;
	return Num;
}
short ReadDay()
{
	short Num;
	cout << "Enter Day : ";
	cin >> Num;
	return Num;
}

short ReadDaysToAdd()
{
	short Num;
	cout << "How Many Days To Add : ";
	cin >> Num;
	return Num;
}

bool LeapYear(int num)
{
	return (num % 100 != 0 && num % 4 == 0) || (num % 400 == 0);
}

int NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumerOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2)
		? (LeapYear(Year) ? 29 : 28)
		: NumerOfDays[Month];

}

int NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
	int TotalOfDays = 0;
	for (int i = 1; i < Month; i++)
	{
		TotalOfDays += NumberOfDaysInAMonth(i, Year);
	}
	TotalOfDays += Day;
	return TotalOfDays;
}

struct sDate
{
	short Year; short Month; short Day;
};

//bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
//{
//	int Date1DaysFromBeginning = NumberOfDaysFromTheBeginningOfTheYear(Date1.Day, Date1.Month, Date1.Year);
//
//	int Date2DaysFromBeginning = NumberOfDaysFromTheBeginningOfTheYear(Date2.Day, Date2.Month, Date2.Year);
//
//
//	if (Date1.Year != Date2.Year)
//	{
//		if (Date1.Year < Date2.Year)
//			return true;
//		else
//			return false;
//	}
//	else
//	{
//		if (Date1DaysFromBeginning < Date2DaysFromBeginning)
//			return true;
//		else
//			return false;
//	}
//
//}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year != Date2.Year)
	{
		if (Date1.Year < Date2.Year)
			return true;
		else
			return false;
	}
	else if (Date1.Month != Date2.Month)
	{
		if (Date1.Month < Date2.Month)
			return true;
		else
			return false;
	}
	else
	{
		if (Date1.Day < Date2.Day)
			return true;
		else
			return false;

	}

}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

int main()
{
	sDate Date1,Date2;

	Date1 = ReadFullDate();

	cout << endl;

	Date2 = ReadFullDate();

	cout << (IsDate1BeforeDate2(Date1, Date2) ? "\nYes, Date1 is Less than Date2." : "\nNo, Date1 is Not Less than Date2.");


	system("pause>0");
	return 0;
}

