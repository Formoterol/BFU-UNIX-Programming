#include<iostream>
using namespace std;
int main() {
	short s = 1;
	int t = 267898765678;
	char a = 'a';
	cout << "short  " << &s << " " << sizeof(s) << endl;
	cout << "int    " << &t << " " << sizeof(t) << endl;
	cout << "char   " << (void*)&a << " " << sizeof(a) << endl;
	return 0;
}