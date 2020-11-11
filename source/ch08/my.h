#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	cout << a << "\t" << b << endl;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;

	cout << a << "\t" << b << endl;
}

void swap_cr(const int& a, const int& b)
{
	int temp1 = a;
	int temp2 = b;

	swap_r(temp1, temp2);
}

namespace X {
	int var;
	void print(){
		cout << var << endl;
	}
}

namespace Y {
	int var;
	void print(){
		cout << var << endl;
	}
}

namespace Z {
	int var;
	void print(){
		cout << var << endl;
	}
}