#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int sum, sub, mul, div, rem = 0;

	cin >> a >> b;

	sum = a + b;
	sub = a - b;
	mul = a * b;
	div = a / b;
	rem = a % b;

	cout << sum << endl;
	cout << sub << endl;
	cout << mul << endl;
	cout << div << endl;
	cout << rem << endl;
}