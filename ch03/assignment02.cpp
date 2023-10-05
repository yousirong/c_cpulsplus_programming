#include <iostream>
#include <iomanip>
using namespace std;

// 윤년 여부를 확인하는 함수
bool YunYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int calculateFirstDayOfWeek(int year, int month) {
	if (month < 3) {
		month += 12;
		year--;
	}
	int k = year % 100;
	int j = year / 100;
	int dayOfWeek = (1 + 13 * (month + 1)) / 5 + k + k / 4 + j / 4 - 2 * j;
	dayOfWeek = (dayOfWeek % 7 + 6) % 7; // 요일을 0에서 6 사이로 맞춤
	return dayOfWeek;
}

// 달력을 출력하는 함수
void printCalendar(int year) {
	string print_month[12] = {
        "January",
        "February",
        "March",
        "April",
        "June",
        "July",
        "August", 
        "September",
        "October", 
        "November",
        "December"
    };

	for (int month = 1; month < 12; ++month) {
		cout <<"     "<< setw(1) << left << print_month[month-1] << " " << year << endl;
		cout << "  M  T  W  T  F  S  S" << endl;

		int daysInMonth;
		switch (month) {
			case 2:
				daysInMonth = YunYear(year) ? 29 : 28;
				break;
			case 4: case 6: case 9: case 11:
				daysInMonth = 30;
				break;
			default:
				daysInMonth = 31;
		}

		int firstDayOfWeek = calculateFirstDayOfWeek(year, month);

// 첫 주에서 요일을 올바른 위치에 맞추기 위한 공백 출력
		for (int day = 0; day < firstDayOfWeek; ++day) {
			cout << "   ";
		}

		for (int day = 1; day <= daysInMonth; ++day) {
			cout<<" " << setw(2) <<right<< day << "";
			if (++firstDayOfWeek > 6) {
				firstDayOfWeek = 0;
				cout << endl;
			}
		}
		cout << endl << endl;
	}
}

int main() {
	int year;
	cin >> year;

	printCalendar(year);

	return 0;
}

/*
문제의 정의 : (간략하게 설명, 예 : 이 문제는 ~~를 이용하여 ~~를 구하는 문제입니다)

문제의 해결 방안 : (간략하게 설명, 예 : ~~부분을 ~~를 이용하여 해결하였으며, ~~한 처리/연산 등을 통해 문제를 해결하였습니다)
*/