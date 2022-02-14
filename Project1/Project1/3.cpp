#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e;
	int mul=0;

	cin >> a;
	cin >> b;

	c = a * (b % 10);
	d = a * ((b / 10) % 10);
	e = a * (((b / 10) / 10) % 10);
	mul = a * b;

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << mul << endl;

}