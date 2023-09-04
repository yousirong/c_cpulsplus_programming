// 1장 연습문제 2

#include <string.h>
#include <iostream>

using namespace std;

int main() {

	int age;

	cout << "나이 : ";
	cin >> age;

	int future;
	future = age + 10;

	cout << "10년 후에는 " << future << "살이 됩니다." << endl;

	return 0;
}