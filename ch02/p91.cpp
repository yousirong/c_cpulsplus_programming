// 도형의 면적 계산하기
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int choice;

	cout << "도형을 선택하세요(1, 2, 3) : ";
	cin >> choice;

	int length;
	int width;
	int radius;

	if (choice == 1) {
		cout << "가로 : ";
		cin >> width;
		cout << "세로 : ";
		cin >> length;

		int area = width * length;
		cout << "면적 : " << area << endl;
	} else if (choice == 2) {
		cout << "반지름 : ";
		cin >> radius;
		
		double area = (double)radius * radius * 3.14;
		cout << "면적 : " << area << endl;
	} else if (choice == 3) {
		cout << "가로 : ";
		cin >> width;
		cout << "세로 : ";
		cin >> length;

		int area = (width * length) / 2;
		cout << "면적 : " << area << endl;
	} else
		cout << "올바르지 못한 선택입니다." << endl;

	return 0;
}