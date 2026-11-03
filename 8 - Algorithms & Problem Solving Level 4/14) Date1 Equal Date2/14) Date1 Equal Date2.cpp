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

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	if (Date1.Year == Date2.Year)
	{
		if (Date1.Month != Date2.Month)
		{
			if (Date1.Day == Date2.Day)
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
	sDate Date1, Date2;

	Date1 = ReadFullDate();

	cout << endl;

	Date2 = ReadFullDate();

	cout << (IsDate1EqualDate2(Date1, Date2) ? "\nYes, Date1 is Equal Date2." : "\nNo, Date1 is Not Equal Date2.");


	system("pause>0");
	return 0;
}