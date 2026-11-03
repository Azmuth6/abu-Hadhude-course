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

	Period.sStartDate = ReadFullDate();
	Period.sEndDate = ReadFullDate();
	return Period;
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	/*
	if (IsDate1AfterDate2(Date1,Date2))
	return enDateCompare::After;
	*/

	//this is faster 

	return enDateCompare::After;
}

bool IsOverLabPeriod(sPeriod Period1, sPeriod Period2)
{
	if (CompareDates(Period2.sEndDate, Period1.sStartDate) == enDateCompare::Before
		|| CompareDates(Period2.sStartDate, Period1.sEndDate) == enDateCompare::After)
		
		return false;
	
	else
		return true;

}

int main()
{
	sPeriod Period1,Period2;

	cout << "Enter First Period\n";
	Period1 = ReadPeriod();

	cout << "Enter Second Period\n";
	Period2 = ReadPeriod();


	if (IsOverLabPeriod(Period1, Period2))
		cout << "Yes , Periods OverLab.";
	else
		cout << "No , Not Periods OverLab.";
	
	system("pause>0");
	return 0;
}