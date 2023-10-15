#include <iostream>
#include <cmath>
using namespace std;

int julian_cal_func(int y, int m, int d)  // 줄리안공식으로 줄리안 값 계산 함수
{
	y += 8000;
	if (m < 3)
	{
		y--;
		m += 12;
	}
	long julian = ((y * 365) + (y / 4) - (y / 100) + (y / 400) - 1200820 + (m * 153 + 3) / 5 - 92 + (d - 1)) % 7;
	return julian;  // 줄리안 값 리턴
}

int result_func(int y, int m, int d)  // 잘못입력될경우 오류 문장 출력과 날짜의 요일을 구하는 함수
{
	string day_week[7] = { "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday", "Sunday" };  // 배열변수에 요일 생성
	if (y < 1583) {  // 년도 오류일 경우
		cout << "Wrong year! Try again!" << endl;
		return -1;
	}
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) { // 윤년인 경우 
		if (m == 2 && d > 29 && d < 1) { //윤년인데 2월달 29일 넘김 -> 일 수 가 틀린 경우 day 오류 출력
			cout << "Wrong day! Try again!" << endl;
			return -1;
		}
		else if (m==1 || m == 3 || m == 7 ||m == 8 ||m == 10 ||m == 12) { //2월 달이 아닌 마지막 날짜가 31일인 달에서 일 수 가 초과된경우  -> day 오류 문장 출력
				if (d < 1 || d>31) {
					cout << "Wrong day! Try again!" << endl;
					return -1;

				}
				
				} else {  // 2월 달이 아닌 마지막 날짜가 30일인 달에서 일 수 가 초과된 경우  -> day 오류 문장 출력
				if (d < 1 || d>30) {
					cout << "Wrong day! Try again!" << endl;
					return -1;
			} 
			}
		}
	
	else {                                       // 윤년이 아닌 경우
		if (m == 2 && d > 28 && d < 1) {  // 윤년이 아닌데 28일 초과 된 경우  -> day 오류 문장 출력
			cout << "Wrong day! Try again!" << endl;
			return -1;
		}
		else if (m==1 || m == 3 || m == 7 ||m == 8 ||m == 10 ||m == 12) {//2월 달이 아닌 마지막 날짜가 31일인 달에서 일 수 가 초과된경우   -> day 오류 문장 출력
				if (d < 1 || d>31) {
					cout << "Wrong day! Try again!" << endl;
					return -1;

				}
				
				} else {
				if (d < 1 || d>30) { // 2월 달이 아닌 마지막 날짜가 30일인 달에서 일 수 가 초과된 경우  -> day 오류 문장 출력
					cout << "Wrong day! Try again!" << endl;
					return -1;
			} 
			}
	}

	if (m < 1 || m> 12) { // 달 오류  -> 달 오류 문장 출력
		cout << "Wrong month! Try again!" << endl;
		return -1;
	}
	/*if (d < 1 || d>31) {

		cout << "Wrong day! Try again!" << endl;
		return -1;

	}*/
	int res = julian_cal_func(y, m, d);  // 줄리안 계산 함수에서 리턴 받아서 변수에 저장 
	cout << y << "-" << m << "-" << d << " is " << day_week[res] << endl;  // 요일 출력
	return 0;
}



int main()
{
	int user_year, user_month, user_day;  // 년도 월 일 입력
	cin >> user_year >> user_month >> user_day;

	result_func(user_year, user_month, user_day);  // 요일 출력해주는 함수에 변수 대입


	return 0;
}

/*
문제의 정의 : 
  이 문제는 줄리안 계산 해주는 함수와 해당날짜 요일을 구해주는 함수(틀릴경우 오류 문장도 출력)를 만들어서 풀이하는 문제입니다.
문제의 해결 방안 : 
		줄리안 값 구해주는 함수 julian_cal_func()을 작성했고, result_func() 줄리안 값을 요일로 출력해주는 함수를 작성했습니다.
		요일 출력은 배열을 아직 안배우긴 했지만 if 구문으로 구현하면 코딩줄이 너무 길어져서 배열변수를 사용해서 요일을 생성했습니다.
		
		if구문으로 년도와 달, 일 순서로 에러구문을 출력시키기 위해 년도 - 달 - 일 순으로 if구문을 통과하도록 작성했습니다. 
		여기서 중요한 점은 return -1를 함으로써 프로그램에서 에러가 났다는 것으로 호출하고 return 0을 하지 않았습니다(return 0을하면 함수가 종료되기 때문에). 
		
		달력에는 윤년도 있지만 30일인 달이 있고, 31일인 달이 있으므로 if구문을 통해 구분해서 day 오류를 출력하도록 작성했습니다. 
		
		
*/