// 1장 연습문제 6

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int hour;
	int minute;
	int second;

	cout << "시 : ";
	cin >> hour;
	cout << "분 : ";
	cin >> minute;
	cout << "초 : ";
	cin >> second;

	const int total_second = (hour * 3600) + (minute * 60) + second;

	cout << endl << "전체 초 : " << total_second << endl;

	return 0;
}