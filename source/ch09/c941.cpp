#include "std_lib_facilities.h"

struct Date {
		int year;
		int month;
		int day;
	};

void init_day(Date& dd, int y, int m, int d)
{
	if (y > 0)
		dd.year = y;
	else
		error("Invalid year");

	if (m <= 12 && m > 0)
		dd.month = m;
	else
		error("Invalid month");

	if (d > 0 && d <= 31)
		dd.day = d;
	else
		error("Invalid day");
};

void add_day(Date& dd, int n)
{
	dd.day += n;
	if (dd.day > 31)
	{
		dd.month++;
		dd.day -= 31;
		if (dd.month > 12)
		{
			dd.year++;
			dd.month -= 12;
		}
	}
}

void c941()
{
	Date today;
	init_day(today, 1978, 6, 25);
	Date tomorrow = today;
	add_day(tomorrow, 1);
	cout << "&9.4.1:" << endl;
	cout << "Today: " << today.year << "." << today.month << "." << today.day << "." << endl;
	cout << "Tomorrow: " << tomorrow.year << "." << tomorrow.month << "." << tomorrow.day << "." << endl;
	Date invalid_date;
	init_day(invalid_date, 2004, 13, -5);
}

int main()
{
	try
	{
		c941();
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}