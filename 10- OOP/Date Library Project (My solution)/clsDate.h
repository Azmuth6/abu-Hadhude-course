#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsDate
{
private:
	int _Day;
	int _Month;
	int _Year;

public:

	clsDate()
	{
		_Day = 1;
		_Month = 1;
		_Year = 2000;
	};

	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	int Day() const { return _Day; }
	int Month() const { return _Month; }
	int Year() const { return _Year; }

	static bool isLeapYear(int num)
	{
		return (num % 100 != 0 && num % 4 == 0) || (num % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static int NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	int NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static long long NumberOfSecondsInAYear(short Year)
	{
		return (long long)NumberOfMinutesInAYear(Year) * 60;
	}

	long long NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static int NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month>12)
			return 0;

		int NumerOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2)
			? (isLeapYear(Year) ? 29 : 28)
			: NumerOfDays[Month];
	}


	int NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}


	static int NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	int NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short d, a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + 12 * a - 2;

		d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] =
		{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder];
	}

	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	}

	static string MonthShortName(short MonthNumber)
	{
		string arrMonthName[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return arrMonthName[MonthNumber - 1];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		// Print the current month name
		printf("\n  _______________%s %d_______________\n\n",
			MonthShortName(Month).c_str(), Year);

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n  _________________________________\n");
	}

	void YearCalendar(short Year)
	{
		printf("\n  ___________________________________\n\n");
		cout << "               Calendar : " << Year;
		printf("\n  ___________________________________\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}

	static int NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
	{
		int TotalOfDays = 0;
		for (int i = 1; i < Month; i++)
		{
			TotalOfDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalOfDays += Day;
		return TotalOfDays;
	}

	int NumberOfDaysFromTheBeginningOfTheYear()
	{
		return NumberOfDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	clsDate GetDateFromDayOrderInYear()
	{
		return GetDateFromDayOrderInYear(NumberOfDaysFromTheBeginningOfTheYear(), _Year);
	}

	static clsDate GetDateFromDayOrderInYearAndAddDays(short DaysForAdd, clsDate Date)
	{
		int RemainingDays = DaysForAdd + NumberOfDaysFromTheBeginningOfTheYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;

		Date._Month = 1;


		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}

			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	clsDate GetDateFromDayOrderInYearAndAddDays()
	{
		int DaysForAdd;
		clsDate Date;

		return GetDateFromDayOrderInYearAndAddDays(DaysForAdd, Date);
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year != Date2._Year)
		{
			if (Date1._Year < Date2._Year)
				return true;
			else
				return false;
		}
		else if (Date1._Month != Date2._Month)
		{
			if (Date1._Month < Date2._Month)
				return true;
			else
				return false;
		}
		else
		{
			if (Date1._Day < Date2._Day)
				return true;
			else
				return false;
		}
	}

	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year == Date2._Year)
		{
			if (Date1._Month != Date2._Month)
			{
				if (Date1._Day == Date2._Day)
				{
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		int DayInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		return (Date._Day == DayInMonth);
	}

	bool IsLastDayInMonth(clsDate Date)
	{
		return IsLastDayInMonth(Date);
	}

	static bool IsLastMonthInYear(clsDate Date)
	{
		return (Date._Month == 12);
	}

	bool IsLastMonthInYear(clsDate Date)
	{
		return IsLastMonthInYear(Date);
	}



	//enough for 15;


};