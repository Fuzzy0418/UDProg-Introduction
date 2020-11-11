#include "std_lib_facilities.h"

struct Date {
		int year;
		int month;
		int day;

		Date(int y, int m, int d);
		void add_day(int n);
};

Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;
	else
		error("Invalid year");

	if (m <= 12 && m > 0)
		month = m;
	else
		error("Invalid month");

	if (d > 0 && d <= 31)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31)
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -=12;
		}
	}
}

void c942()
{
	Date today(1978, 6, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);
	cout << "&9.4.2:" << endl;
	cout << "Today: " << today.year << "." << today.month << "." << today.day << "."<< endl;
	cout << "Tomorrow: " << tomorrow.year << "." << tomorrow.month << "." << tomorrow.day << "." << endl;
	Date invalid_date = Date(2004, 13, -5);
}

int main()
{
	try
	{
		c942();
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}