// 2장 연습문제 5

#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	int sum = 0;

	do {
		cout << "정수를 입력하시오 : ";
		cin >> num;
		sum += num;
	} while (num != 0);

	cout << "합계 : " << sum << endl;

	return 0;
}