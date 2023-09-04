// 2장 연습문제 15

#include <iostream>
#include <time.h>
using namespace std;

int main() {

	srand(time(NULL));

	int computerChoice = rand() % 3 + 1;

	int userChoice;

	cout << "가위, 바위, 보 중에 하나를 선택하시오(1=가위, 2=바위, 3=보) : ";
	cin >> userChoice;
	
	cout << "당신의 선택 : ";
	switch (userChoice) {
	case 1: cout << "가위";
		break;
	case 2: cout << "바위";
		break;
	case 3: cout << "보";
		break;
	default: cout << "올바르지 못한 선택입니다.";
		break;
	}

	cout << endl << "컴퓨터 : ";
	switch (computerChoice) {
	case 1: cout << "가위" << endl;
		if (userChoice == 2)
			cout << "사용자 승!" << endl;
		else if (userChoice == 3)
			cout << "사용자 패!" << endl;
		else cout << "비겼습니다!" << endl;
		break;

	case 2: cout << "바위" << endl;
		if (userChoice == 1)
			cout << "사용자 패!" << endl;
		else if (userChoice == 3)
			cout << "사용자 승!" << endl;
		else cout << "비겼습니다!" << endl;
		break;

	case 3: cout << "보" << endl;
		if (userChoice == 2)
			cout << "사용자 승!" << endl;
		else if (userChoice == 1)
			cout << "사용자 패!" << endl;
		else cout << "비겼습니다!" << endl;
		break;
	}

	return 0;

}