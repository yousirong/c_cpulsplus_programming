// 1�� �������� 6

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int hour;
	int minute;
	int second;

	cout << "�� : ";
	cin >> hour;
	cout << "�� : ";
	cin >> minute;
	cout << "�� : ";
	cin >> second;

	const int total_second = (hour * 3600) + (minute * 60) + second;

	cout << endl << "��ü �� : " << total_second << endl;

	return 0;
}