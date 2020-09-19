#include<iostream>
#include<iomanip>
using namespace std;
int summary(int b, int c)
{
	return (b + c);
}
int main() {
	char character = 'b';
	int integer = 20200919;
	double decimal1 = 2020.919;
	long longint1 = 20200919;
	long long longint2 = 202009192020;
	float decimal2 = 2020.919;
	unsigned int a = -1100001;

	cout << hex << (void*)&character << '\t' << sizeof(character) <<'\t'<<"char"<< endl;
	cout << hex << &integer << '\t' << sizeof(integer) << '\t' << "int" << endl;
	cout << hex << &decimal1 << '\t' << sizeof(decimal1) << '\t' << "double" << endl;
	cout << hex << &longint1 << '\t' << sizeof(longint1) << '\t' << "long" << endl;
	cout << hex << &longint2 << '\t' << sizeof(longint2) << '\t' << "long long" << endl;
	cout << hex << &decimal2 << '\t' << sizeof(decimal2) << '\t' << "float" << endl;
	cout << hex << &a << '\t' << sizeof(a) << '\t' << "unsigned" << endl;
	cout << hex << (void*)summary << '\t' << "function" << endl;
	//cout << hex << (void*)summary << endl << '\t' << sizeof(summary) << endl;
	return 0;
}