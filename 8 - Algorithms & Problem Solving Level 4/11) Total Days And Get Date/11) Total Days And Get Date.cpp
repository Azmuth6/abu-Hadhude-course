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
{ short Year; short Month; short Day; };

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
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



int main()
{
	short Day = ReadDay();
	short Month = ReadMonth(); 
	short Year = ReadYear(); 
	short DaysOrderInYear = NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);

	cout << "\nNumber of Days from the beginning of the year is " << DaysOrderInYear << "\n\n";
	
	sDate Date;   
	
	Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year); 
	cout << "Date for [" << DaysOrderInYear << "] is: ";  
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;   
	
	system("pause>0");
	return 0;
}

