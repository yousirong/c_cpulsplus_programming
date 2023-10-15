#include <iostream>
#include <iomanip>
using namespace std;

// 윤년 여부를 확인하는 함수
bool YunYear(int yr) {
	return (yr % 4 ==0 &&yr %100 != 0) ||(yr%400== 0);
}

// month에 day가 몇인지 계산해주는 함수 - 요일 구하기 과제에서 차용 및 변형
int cal_first_day_month(int yr, int mo) {
	if (mo < 3) {  // 그레고리안 달력에서 1월과 2월은 연도의 뒷부분에 추가로 붙는 13월과 14월로 처리되는 경우를 고려한 것입니다.
		mo += 12;
		yr--;
	}
	int kf = yr% 100;  //연도(yr)를 100으로 나눈 나머지를 kf에 저장
	int js = yr/ 100;  //연도를 100으로 나눈 몫을 js에 저장  
	//위와 같이 따로 변수를 생성해서 연도를 2개로 나눠 처리

	int ow = (1+13*(mo + 1)) / 5 + kf + kf / 4 + js / 4 - 2 * js; //이 식은 Zeller's Congruence(젤러 합동식)라고 불리는 알고리즘을 사용  - 자세한 식에 대한 설명은 밑에 주석에 설명
	ow = (ow % 7+6) % 7; // 요일을 0에서 6 사이로 맞춤
	return ow;
}

// 달력을 출력하는 함수
void print_calendar(int yr) {
	string print_month[12] = { // string 배열에 출력될 1~12월달 이름 초기화해서 배열 생성
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

	for (int m =1;m<12;++m) { // for구문으로 12월달까지 1을 더하면서
		cout <<"     "<< setw(1) <<left<< print_month[m-1] << " " << yr << endl;  // left를 사용함으로써  왼쪽 정렬 시키고 달과 년도 출력
		cout << "  M  T  W  T  F  S  S" << endl; // 예시 출력을 보면 January에서 J가  T위에 위치한것을 볼 수 있습니다. 
// 달의 글자는 무조건 T의 위에 위치하도록 함.
		int days_I_Mo;  // month에 day가 몇인지 case에 따라 대입
		switch (m) {  // switch 함수로 month와 day 계산
			case 2:  // 유년 2월 day 판단
				days_I_Mo =YunYear(yr) ? 29:28;
				break;
			case 4: case 6: case 9: case 11:  //month 30일인 경우 
				days_I_Mo =30;  
				break;
			default:                          // month 31일인 경우
				days_I_Mo =31;
		}

		int first_day_week= cal_first_day_month(yr, m);  // 새로운 변수에 

      // 첫 주에서 요일을 올바른 위치에 맞추기 위한 공백 출력
		for (int d= 0; d<first_day_week; ++d) {
			cout <<"   ";
		}

		for(int d=1;d<=days_I_Mo;++d) {
			cout<<" "<<setw(2)<<right<<d <<"";  // setw(2) << right으로 day를 오른쪽 정렬 시킴
			if (++first_day_week>6) { // 월~일요일까지 출력시키고 
				first_day_week=0;   // 0을 대입함으로써 다음주 월요일로 출력시키도록함
				cout <<endl;
			}
		}
		cout <<endl<<endl;  // 달과 달사이에 한줄 띄워져 있음

	}
}

int main() {
	int year;
	cin >>year; // 사용자에서 년도 입력받기

	print_calendar(year); // 달력 출력해주는 함수에 년도 대입

	return 0;
}

/*
문제의 정의 : 
윤년의 파악과 12달 각각 해당하는 day 수 파악, 여백을 계산하여 예시의 출력과 완전히 같게 달력 날짜의 출력을 시키는 문제입니다. 

문제의 해결 방안 : 
윤년을 파악하는 함수를 yr % 4 ==0 &&yr %100 != 0) ||(yr%400== 0) 윤년 계산 공식을 통해 작성하였습니다.

cal_first_day_month() 함수 설명
(1 + 13 * (mo + 1)) / 5: mo(month) 값을 이용하여 mo(month)에 따른 값을 계산,
kf + kf / 4 + js / 4 - 2 * js: 연도와 연도의 일부(100으로 나눈 나머지와 몫)를 이용하여 연도에 따른 값을 계산,
ow = (ow % 7 + 6) % 7: 계산된 요일 값을 0에서 6 사이로 맞추기 위해 사용. 이 부분은 계산된 ow 값이 음수가 될 경우를 처리하고, 요일을 0부터 6까지의 값으로 변환했습니다.

print_calendar()함수에서는 배열변수에 달을 순서대로 넣어서 차례대로 출력할 수 있도록 작성하였습니다.
다음으로는 요일을 여백에 맞게 출력시킬 수 있도록 for구문과 조건문을 사용하였으며 switch함수를 사용하여 달의 마지막요일을 출력시킬 수 있도록 하였습니다.
for구문으로 day를 하나 씩 출력시키면서 7일을 지키면서 한 주의 마지막 요일이면 다음줄로 넘어가게 작성하였습니다.

달력 요일은 오른쪽 정렬 시켰으며 여백을 철저하게 지켜서 해결하였습니다.
*/