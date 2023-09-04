// 2장 연습문제 11

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int n;

	cout << "n의 값을 입력하시오 : ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum += i * i;
	}

	cout << "계산 값은 " << sum << "입니다. " << endl;

	return 0;
}