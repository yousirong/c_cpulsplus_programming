// 산수 문제 자동 출제
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	int answer;

	cout << "산수 문제를 출제합니다." << endl;

	while (true) {
		int x = rand() % 100;
		int y = rand() % 100;
		cout <<endl<< x << "+" << y << " = ";
		cin >> answer;
		if (answer == (x + y))
			cout << "정답입니다." << endl;
		else
			cout << "오답입니다. 정답은 " << x + y << endl;
	}
	return 0;
}