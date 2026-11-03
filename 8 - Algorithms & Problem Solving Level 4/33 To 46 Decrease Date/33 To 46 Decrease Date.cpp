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

bool IsFirstDayInMonth(sDate Date)
{
	return (Date.Day == 1);
}

bool IsFirstMonthInYear(sDate Date)
{
	return (Date.Month == 1);
} 

//-----------------------------------------------------------------------
sDate DecreaseDateByOneDay(sDate& Date)
{	
		if (IsFirstDayInMonth(Date))
		{
			if (IsFirstMonthInYear(Date))
			{
				Date.Month = 12;
				Date.Year--;
				Date.Day = 31;
			}
			else
			{
				Date.Month--;
				short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
				Date.Day = DaysInMonth;
			}
		}
		else
			Date.Day--;
	

	return Date;
}
//----------------------------------------------------------------------
sDate DecreaseDateByXDay(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
//-----------------------------------------------------------------------

sDate DecreaseDateByOneWeak(sDate& Date)
{
	for (int i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

//-----------------------------------------------------------------------

sDate DecreaseDateByXWeak(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = DecreaseDateByOneWeak(Date);
	}
	return Date;
}

//--------------------------------------------------------------------------

sDate DecreaseDateByOneMonth(sDate& Date)
{
	if (IsFirstMonthInYear(Date))
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	int DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;


	return Date;
}

//-------------------------------------------------------------------------------

sDate DecreaseDateByXMonth(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

//-------------------------------------------------------------------------------------------


sDate DecreaseDateByOneYear(sDate& Date)
{
	Date.Year--;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//-----------------------------------------------------------------------------------

sDate DecreaseDateByXYear(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

//-------------------------------------------------------------------------------------

sDate DecreaseDateByXYearFaster(int x, sDate& Date)
{
	Date.Year -= x;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//--------------------------------------------------------------------------------------------

sDate DecreaseDateByOneDecades(sDate& Date)
{
	Date.Year -= 10;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//------------------------------------------------------------------------------------------------

sDate DecreaseDateByXDecades(int x, sDate& Date)
{
	for (int i = 0; i < x; i++)
	{
		Date = DecreaseDateByOneDecades(Date);
	}

	return Date;
}

//--------------------------------------------------------------------------------------------

sDate DecreaseDateByXDecadesFaster(int x, sDate& Date)
{
	Date.Year -= (10 * x);

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;


	return Date;
}

//---------------------------------------------------------------------------------------------


sDate DecreaseDateByOneCentury(sDate& Date)
{
	Date.Year -= 100;

	short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
		Date.Day = DaysInMonth;

	return Date;
}

//--------------------------------------------------------------------------------------------------


sDate DecreaseDateByOneMillennium(sDate& Date)
{
	Date.Year -= 1000;

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
	PrintDate("01-Subtracting one day is: ", DecreaseDateByOneDay(Date));
	PrintDate("02-Subtracting 10 days is: ", DecreaseDateByXDay(10, Date));
	PrintDate("03-Subtracting one week is: ", DecreaseDateByOneWeak(Date));
	PrintDate("04-Subtracting 10 weeks is: ", DecreaseDateByXWeak(10, Date));
	PrintDate("05-Subtracting one month is: ", DecreaseDateByOneMonth(Date));
	PrintDate("06-Subtracting 5 months is: ", DecreaseDateByXMonth(5, Date));
	PrintDate("07-Subtracting one year is: ", DecreaseDateByOneYear(Date));
	PrintDate("08-Subtracting 10 years is: ", DecreaseDateByXYear(10, Date));
	PrintDate("09-Subtracting 10 Years (faster) is: ", DecreaseDateByXYearFaster(10, Date));
	PrintDate("10-Subtracting one Decade is: ", DecreaseDateByOneDecades(Date));
	PrintDate("11-Subtracting 10 Decades is: ", DecreaseDateByXDecades(10, Date));
	PrintDate("12-Subtracting 10 Decade (faster) is: ", DecreaseDateByXDecadesFaster(10, Date));
	PrintDate("13-Subtracting One Century is: ", DecreaseDateByOneCentury(Date));
	PrintDate("14-Subtracting One Millennium is: ", DecreaseDateByOneMillennium(Date));


	system("pause>0");
	return 0;
}

