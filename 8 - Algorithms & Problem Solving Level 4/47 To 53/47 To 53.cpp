#pragma warning(disable : 4996)

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

bool LeapYear(int Year)
{
	return (Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0);
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

struct sDate
{
	short Year; short Month; short Day;
};

sDate TimeNow()
{
	sDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

bool IsLastDayInMonth(sDate Date) 
{ 
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
} 

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2) 
{
	return  (Date1.Year < Date2.Year) ? true 
			: ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true
			: (Date1.Month == Date2.Month ? Date1.Day < Date2.Day 
			: false)) : false); 
}

sDate IncreaseDateByOneDay(sDate Date)
{ 
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month)) 
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++; 
		} 
		else
		{ 
			Date.Day = 1; 
			Date.Month++;
		} 
	} 
	else
	{ Date.Day++; }
	
	return Date;
}


int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1); 
	} 
	return IncludeEndDay ? ++Days : Days; }

short DayOfWeekOrder(sDate Date)
{
	short d, a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + 12 * a - 2;

	d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] =
	{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(sDate Date)
{
	short DayOfWeekOrderForName = DayOfWeekOrder(Date);
	return DayOfWeekOrderForName == 6;
}


bool IsWeekEnd(sDate Date)
{
	short DayOfWeekOrderForName = DayOfWeekOrder(Date);
	

	return (DayOfWeekOrderForName == 6 || DayOfWeekOrderForName == 5);

}

bool IsBusinessDay(sDate Date)
{
	/*short DayOfWeekOrderForName = DayOfWeekOrder(Date);
	string DayName = DayShortName(DayOfWeekOrderForName);

	if (DayName == "Sat" || DayName == "Fri")
		return false;
	else
		return true;*/

	return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilTheEndOfMonth(sDate Date1) 
{
	sDate EndOfMontDate; 
	EndOfMontDate.Day = NumberOfDaysInAMonth(Date1.Month, Date1.Year);  
	EndOfMontDate.Month = Date1.Month;
	EndOfMontDate.Year = Date1.Year;
	
	return GetDifferenceInDays(Date1, EndOfMontDate, true); 
}

short DaysUntilTheEndOfYear(sDate Date1) 
{
	sDate EndOfYearDate; 
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12; 
	EndOfYearDate.Year = Date1.Year;
	
	return GetDifferenceInDays(Date1, EndOfYearDate, true); 
}

void PrintDate(sDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}


int main()
{
	sDate Date = TimeNow();

	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , ";
	PrintDate(Date);

	cout << "\nIs it End of Week?\n";
	if (IsEndOfWeek(Date))
		cout << "Yes it is end of week.\n";
	else
		cout << "No Not end of week.\n";

	cout << "\nIs it Weekend?\n";
	if (IsWeekEnd(Date))
		cout << "Yes it is a week end.\n";
	else
		cout << "No it is NOT a week end.\n";

	cout << "\nIs it Business Day?\n";
	if (IsBusinessDay(Date))
		cout << "Yes it is a business day.\n";
	else
		cout << "No it is NOT a business day.\n";

	cout << endl;
	cout << "Days until end of week   : " << DaysUntilTheEndOfWeek(Date) << " Day(s).\n";
	cout << "Days until end of month  : " << DaysUntilTheEndOfMonth(Date) << " Day(s).\n";
	cout << "Days until end of year   : " << DaysUntilTheEndOfYear(Date) << " Day(s).\n";

	system("pause>0");
	return 0;
}