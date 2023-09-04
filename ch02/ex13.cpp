// 2장 연습문제 13
// ***

#include <iostream>
using namespace std;

int main() {
	int num;
	int temp;
	int a = 0;
	int b = 1;

	cout << "몇 항까지 구할까요 : ";
	cin >> num;

	cout << a << " " << b << " ";

	for (int i = 2; i < num; i++) {
		temp = b;
		b = a + b;
		a = temp;

		cout << b << " ";
	}

	return 0;
}