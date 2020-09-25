#include<iostream>
using namespace std;
int main() {
	char a = 'a';
	short s = 1;
	int t = 267898765678;
	cout << "char   " << (void*)&a << " " << sizeof(a) << endl;
	cout << "short  " << &s << " " << sizeof(s) << endl;
	cout << "int    " << &t << " " << sizeof(t) << endl;
	return 0;
}