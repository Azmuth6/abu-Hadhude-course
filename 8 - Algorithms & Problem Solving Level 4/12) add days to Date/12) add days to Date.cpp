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

sDate GetDateFromDayOrderInYear(short DaysForAdd, sDate Date)
{
	int RemainingDays = DaysForAdd + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;

	Date.Month = 1;


	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}

		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
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
	sDate Date;
	Date = ReadFullDate();

	int DaysOrderInYear = ReadDaysToAdd();

	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Date);
	cout << "Date for [" << DaysOrderInYear << "] is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}

