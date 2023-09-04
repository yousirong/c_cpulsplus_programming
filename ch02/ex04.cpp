// 2장 연습문제 4

#include <iostream>
using namespace std;

int main() {

	int number;
	int box[5] = { 0 };
	int i;

	for (i = 0; i < 5; i++) {
		cout << "정수를 다섯번 입력합니다.";
		cin >> number;
		box[i] = number;
	}
	if (box[0] == 5 || box[1]==5 || box[2] == 5 || box[3] == 5 || box[4] == 5)
		cout << "5를 입력하였군요! 컴퓨터 승" << endl;
	else
		cout << "인내심이 강합니다. 사용자 승" << endl;

return 0;
}