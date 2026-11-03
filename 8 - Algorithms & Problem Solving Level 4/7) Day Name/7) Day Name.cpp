#include <iostream>

using namespace std;

short ReadYears()
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short d, a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;
	
	d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string DayShortName(short DayOfWeekOrder)
{ 
	string arrDayNames[] = 
	{ "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	
	return arrDayNames[DayOfWeekOrder];
}

int main()
{
	short Year = ReadYears();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year); 
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));
}

