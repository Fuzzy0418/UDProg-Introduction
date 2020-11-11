#include "std_lib_facilities.h"

class Date {
public:
	enum Month {
		jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Invalid {};

	Date(int y, Month m, int d): year(y), month(m), day(d) { if(!is_valid()) throw Invalid{}; }
	Date(): year(2001), month(Month::jan), day(1) {};

	bool is_valid();

	void add_year(int n);
	void add_day(int n);

	int get_year() const { return year; }
	Month get_month() const { return month; }
	int get_day() const { return day; }

	bool leapyear(int y) { return (y%4 == 0 && y%100 != 0) || y%400 == 0; }
private:
	int year, day;
	Month month;
};

Date::Month operator++(Date::Month& month)
{
	month = (month == Date::Month::dec) ? Date::Month::jan : Date::Month(int(month)+1);
	return month;
}

bool Date::is_valid()
{
	int tempDay = 31;

	if (day < 1 || day > 31)
		return false;
	else if (year < 0)
		return false;

	switch (month)
	{
		case Date::Month::feb:
			tempDay = (Date::leapyear(year)) ? 29 : 28;
			break;
		case Date::Month::apr:
			tempDay = 30;
			break;
		case Date::Month::jun:
			tempDay = 30;
			break;
		case Date::Month::sep:
			tempDay = 30;
			break;
		case Date::Month::nov:
			tempDay = 30;
			break;
	}

	if (tempDay < day)
		return false;

	return true;
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31)
	{
		++month;
		day -= 31;
		if (month == Date::Month::jan)
		{
			year++;
		}
	}
}

void Date::add_year(int n)
{
	year++;
}

void c974()
{
	Date default_date;
	Date today(1978, Date::jun, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);
	Date next_year = today;
	next_year.add_year(1);
	cout << "&9.7.4:" << endl;
	cout << "Default date: " << default_date.get_year() << "." << default_date.get_month() << "." << default_date.get_day() << "." << endl;
	cout << "Today: " << today.get_year() << "." << today.get_month() << "." << today.get_day() << "."<< endl;
	cout << "Tomorrow: " << tomorrow.get_year() << "." << tomorrow.get_month() << "." << tomorrow.get_day() << "." << endl;
	cout << "Next year: " << next_year.get_year() << "." << next_year.get_month() << "." << next_year.get_day() << "." << endl;
	Date invalid_date = Date(2004, Date::dec, -5);
}

int main()
{
	try
	{
		c974();
		return 0;
	}
	catch(Date::Invalid&)
	{
		cout << "Invalid date" << endl;
		return 1;
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}
}