#include <iostream>
using namespace std;

int main() {
	int A, B, C; // INT_MAX의 값은 2147483647이므로, 초과하면 오류 발생 
	int mul = 0;

	try 
	{
		// 값 입력 시, 2147483647보다 큰 값을 입력하면 오류 발생 
		cin >> A;
		if (A < 0)
		{
			throw - 1;
		}
		cin >> B;
		if (B < 0)
		{
			throw - 1;
		}
		cin >> C;
		if (C < 0)
		{
			throw - 1;
		}
		
	}
	catch (int)
	{
		cout << "입력값에는 음수값 혹은 정수 최댓값을 받을 수 없습니다." << endl;
		return -1;
	}
	try
	{
		mul = A * B * C;

		if (mul < 0)
		{
				throw -1;
		}
	}
	catch (int)
	{
		cout << "오버플로우 발생" << endl;
		return -2;
	}

	cout << mul << endl;

	return 0;
}