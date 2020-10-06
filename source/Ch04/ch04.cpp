#include "std_lib_facilities.h"

bool acceptedUnit(string unit)
{
	bool accepted = false;

	if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
	{
		accepted = true;
	}

	return accepted;
}

constexpr double cm_to_m = 0.01;
constexpr double in_to_m = 2.54*cm_to_m;
constexpr double ft_to_m = 12.0*in_to_m;

double value_to_meter (double value, string unit)
{
	if (unit == "cm")
		return value * cm_to_m;
	else if (unit == "in")
		return value * in_to_m;
	else if (unit == "ft")
		return value * ft_to_m;
	else
		return value;

}

int main()
{
	cout << "Enter a double value and unit: ";

	double value = 0;
	string unit = "";
	double smallest = 999999;
	double largest = -999999;
	double convertedVal = 0;
	int count = 0;
	double sum = 0;
	vector<double> values;

	while (cin >> value >> unit)
	{

		if (acceptedUnit(unit))
		{
			cout << value << " " << unit;
			convertedVal = value_to_meter(value, unit);
			count++;
			sum += convertedVal;
			values.push_back(convertedVal);

			if (convertedVal < smallest)
			{
				cout << " the smallest so far.\n";
				smallest = convertedVal;
			}
			else if (convertedVal > largest)
			{
				cout << " the largest so far.\n";
				largest = convertedVal;
			}
			else
				cout << "\n";
		}
		else
			cout << "this unit isn't accepted\n";

	}

	cout << "The smallest value: " << smallest << "m\n";
	cout << "The largest value: " << largest << "m\n";
	cout << "Number of values: " << count << " db\n";
	cout << "The sum of values: " << sum << "m\n";

	cout << "The entered values: ";
	sort(values); // értékek rendezése növekvő sorrendbe
	
	for (double value:values)
	{
		cout << value << ", ";
	}
	cout << "\n";

	return 0;
}