#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to: ";
	string first_name = "";
	cin >> first_name;

	cout << "Dear " << first_name << ",\n";
	cout << "How are you? I am fine. I miss you.\n";
	cout << "When are you coming home? We are looking forward to it.\n";
	cout << "We hope you feel good and then write a letter about it.\n";

	cout << "Enter the name of another friend: ";
	string friend_name = "";
	cin >> friend_name;

	cout << "Have you seen " << friend_name << "?\n";

	char friend_sex = 0;
	cout << "What is your friend gender? (f/m): ";
	cin >> friend_sex;

	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex == 'f')
		cout << "If you see" << friend_name << " please ask her to call me.\n";


	int age = 0;
	cout << "How old are you?: ";
	cin >> age;
	
	cout << "I hear you just had a birthday and you are " << age << " years old.\n";

	if (age <= 0 or age >= 110)
		error("you're kidding!");
	else if (age < 12)
		cout << "Next year you will be " << age+1 <<".\n";
	else if (age == 17)
		cout << "Next year you will be able to vote.\n";
	else if (age >= 70)
		cout << "I hope you are enjoying retirement.\n";

	cout << "Yours sincerely, Dobos Máté\n";

	return 0;
}