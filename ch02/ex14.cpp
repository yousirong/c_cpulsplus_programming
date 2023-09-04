// 2장 연습문제 14

#include <iostream>
using namespace std;

int main() {
	char ch;

	cout << "연산의 종류(+,-,*,/) : ";
	cin >> ch;

	int x, y;
	cout << "숫자를 입력하시오 : ";
	cin >> x >> y;
	
	switch (ch) {
	case '+':
		cout << "계산의 결과 : " << x + y << endl;
		break;
	case '-':
		cout << "계산의 결과 : " << x - y << endl;
		break;
	case '*':
		cout << "계산의 결과 : " << x * y << endl;
		break;
	case '/':
		if (y > 0)
			cout << "계산의 결과 : " << x / y << endl;
		else
			cout << "분모가 0인 경우는 계산이 불가능합니다." << endl;
		break;
	}

	return 0;

}