// 2장 연습문제 2

#include <iostream>
using namespace std;

int main() {
	
	int drinkNumber;

	cout << "콜라, 물, 스프라이트, 주스, 커피 중에서 하나를 선택하세요 : ";
	cin >> drinkNumber;
	switch (drinkNumber) {
	case 1:
		cout << "콜라를 선택했습니다."; 
		break;
	case 2:
		cout << "물을 선택했습니다."; 
		break;
	case 3:
		cout << "스프라이트를 선택했습니다."; 
		break;
	case 4:
		cout << "주스를 선택했습니다."; 
		break;
	case 5:
		cout << "커피를 선택했습니다."; 
		break;
	default:
		cout << "오류. 선택이 유효하지 않습니다. 돈을 반환합니다."; 
		break;
	}
	return 0;
}