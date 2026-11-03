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
	{
		Date.Day++;
	}

	return Date;
}


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



bool IsWeekEnd(sDate Date)
{
	short DayOfWeekOrderForName = DayOfWeekOrder(Date);


	return (DayOfWeekOrderForName == 6 || DayOfWeekOrderForName == 5);

}

short VacationDays(sDate Date1, sDate Date2)
{
	short Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if ( !IsWeekEnd(Date1))
		{
			Days++;
		}
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return Days;
}

void PrintDate(sDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

sDate ReadFullDate() {
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

int main()
{
	cout << "\nVacation Start From : \n";
	sDate Date1 = ReadFullDate();

	cout << "\nVacation End At     : \n";
	sDate Date2 = ReadFullDate();

	cout << "\nVacation From : " << DayShortName(DayOfWeekOrder(Date1)) << " , ";
	PrintDate(Date1);

	cout << "Vacation To   : " << DayShortName(DayOfWeekOrder(Date2)) << " , ";
	PrintDate(Date2);

	cout << "\n-------------------------------------\n";
	cout << "Actual Vacation Days (without weekends): "
		<< VacationDays(Date1, Date2) << " Day(s).\n";

	system("pause>0");
	return 0;
}
