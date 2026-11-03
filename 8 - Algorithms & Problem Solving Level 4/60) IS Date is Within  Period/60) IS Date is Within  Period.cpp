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

struct sDate
{
	short Year; short Month; short Day;
};
struct sPeriod
{
	sDate sStartDate;
	sDate sEndDate;
};


bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true
		: ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true
			: (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
			: false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ?
		((Date1.Month == Date2.Month) ?
			((Date1.Day == Date2.Day) ? true : false) : false)
		: false;
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1EqualDate2(Date1, Date2) && !IsDate1BeforeDate2(Date1, Date2));
}


sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

sPeriod ReadPeriod()
{
	sPeriod Period;

	cout << "\nEnter Start Date:\n";
	Period.sStartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.sEndDate = ReadFullDate();

	return Period;
}

bool isDateIsWithinPeriod(sDate Date, sPeriod Period)
{
	return (IsDate1BeforeDate2(Period.sStartDate, Date) && IsDate1AfterDate2(Period.sEndDate, Date));
}

int main()
{
	sPeriod Period1;

	cout << "Enter First Period\n";
	Period1 = ReadPeriod();

	sDate Date;

	cout << "\n\nEnter Date\n";
	Date = ReadFullDate();

	if (isDateIsWithinPeriod(Date, Period1))
		cout << "\nIn Period\n";
	else
		cout << "\nNot In Period\n";

	system("pause>0");
	return 0;
}