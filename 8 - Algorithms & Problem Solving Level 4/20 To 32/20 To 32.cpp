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

struct sDate
{
	short Year; short Month; short Day;
};

bool IsLastDayInMonth(sDate Date)
{
	int DayInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	return (Date.Day == DayInMonth);
}

bool IsLastMonthInYear(sDate Date)
{
	return (Date.Month >= 12);
}
//-----------------------------------------------------------------------
sDate IncreaseDateByOneDay(sDate &Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
		Date.Day++;

	return Date;
}
//----------------------------------------------------------------------
sDate IncreaseDateByXDay(int x, sDate &Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
//-----------------------------------------------------------------------

sDate IncreaseDateByOneWeak(sDate &Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

//-----------------------------------------------------------------------

sDate IncreaseDateByXWeak(int x, sDate &Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = IncreaseDateByOneWeak(Date);
	}
	return Date;
}

//--------------------------------------------------------------------------

sDate IncreaseDateByOneMonth(sDate &Date)
{
	Date.Month++;

	if (IsLastMonthInYear(Date))
	{	
		Date.Month = 1;
		Date.Year++;
	}

	int DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;


	return Date;
}

//-------------------------------------------------------------------------------

sDate IncreaseDateByXMonth(int x, sDate &Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

//-------------------------------------------------------------------------------------------


sDate IncreaseDateByOneYear(sDate& Date)
{
	Date.Year++;
	
	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//-----------------------------------------------------------------------------------

sDate IncreaseDateByXYear(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

//-------------------------------------------------------------------------------------

sDate IncreaseDateByXYearFaster(int x, sDate& Date)
{
	Date.Year += x;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//--------------------------------------------------------------------------------------------

sDate IncreaseDateByOneDecades(sDate& Date)
{
	Date.Year += 10;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//------------------------------------------------------------------------------------------------

sDate IncreaseDateByXDecades(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = IncreaseDateByOneDecades(Date);
	}

	return Date;
}

//--------------------------------------------------------------------------------------------

sDate IncreaseDateByXDecadesFaster(int x, sDate& Date)
{
	Date.Year += (10 * x);

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;
	

	return Date;
}

//---------------------------------------------------------------------------------------------


sDate IncreaseDateByOneCentury(sDate& Date)
{
	Date.Year += 100;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//--------------------------------------------------------------------------------------------------


sDate IncreaseDateByOneMillennium(sDate& Date)
{
	Date.Year += 1000;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//-----------------------------------------------------------------------------------------------------


sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

void PrintDate(string msg, sDate Date)
{
	cout << msg << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{
	sDate Date;
	Date = ReadFullDate();
	cout << "\nDate After adding\n\n";
	PrintDate("01-Adding one day is: ", IncreaseDateByOneDay(Date));
	PrintDate("02-Adding 10 days is: ", IncreaseDateByXDay(10, Date));
	PrintDate("03-Adding one week is: ", IncreaseDateByOneWeak(Date));
	PrintDate("04-Adding 10 weeks is: ", IncreaseDateByXWeak(10, Date));
	PrintDate("05-Adding one month is: ", IncreaseDateByOneMonth(Date));
	PrintDate("06-Adding 5 months is: ", IncreaseDateByXMonth(5, Date));
	PrintDate("07-Adding one year is: ", IncreaseDateByOneYear(Date));
	PrintDate("08-Adding 10 years is: ", IncreaseDateByXYear(10, Date));
	PrintDate("09-Adding 10 Years (faster) is: ", IncreaseDateByXYearFaster(10, Date));
	PrintDate("10-Adding one Decade is: ", IncreaseDateByOneDecades(Date));
	PrintDate("11-Adding 10 Decades is: ", IncreaseDateByXDecades(10, Date));
	PrintDate("12-Adding 10 Decade (faster) is: ", IncreaseDateByXDecadesFaster(10, Date));
	PrintDate("13-Adding One Century is: ", IncreaseDateByOneCentury(Date));
	PrintDate("14-Adding One Millennium is: ", IncreaseDateByOneMillennium(Date));


	system("pause>0");
	return 0;
}

