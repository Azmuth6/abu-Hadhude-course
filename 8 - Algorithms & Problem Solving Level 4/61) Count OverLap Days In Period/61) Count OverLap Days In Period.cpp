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

bool isLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year) {
	if (Month < 1 || Month > 12) return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(sDate Date) {
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date) {
	if (IsLastDayInMonth(Date)) {
		if (IsLastMonthInYear(Date.Month)) {
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else {
			Date.Day = 1;
			Date.Month++;
		}
	}
	else {
		Date.Day++;
	}
	return Date;
}

int PeriodLengthInDays(sPeriod Period1, bool IncludeEndDay = false) {
	int Days = 0;
	while (IsDate1BeforeDate2(Period1.sStartDate, Period1.sEndDate)) {
		Days++;
		Period1.sStartDate = IncreaseDateByOneDay(Period1.sStartDate);
	}
	return IncludeEndDay ? ++Days : Days;
}

bool isDateIsWithinPeriod(sDate Date, sPeriod Period)
{
	return (IsDate1BeforeDate2(Period.sStartDate, Date) && IsDate1AfterDate2(Period.sEndDate, Date));
}


int CountOverlapDays(sPeriod Period1, sPeriod Period2)
{
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;


	if (!IsOverLabPeriod(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.sStartDate, Period1.sEndDate))
		{
			if (isDateIsWithinPeriod(Period1.sStartDate, Period2))
				OverlapDays++;

			Period1.sStartDate = IncreaseDateByOneDay(Period1.sStartDate);

		}
	}
	
	else
	{
		while (IsDate1BeforeDate2(Period2.sStartDate, Period2.sEndDate))
		{
			if (isDateIsWithinPeriod(Period2.sStartDate, Period1))
				OverlapDays++;

			Period2.sStartDate = IncreaseDateByOneDay(Period2.sStartDate);

		}
	}

	return OverlapDays;
	
}


int main()
{
	sPeriod Period1, Period2;

	cout << "Enter First Period\n";
	Period1 = ReadPeriod();

	cout << "Enter Second Period\n";
	Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);

	system("pause>0");
	return 0;
}