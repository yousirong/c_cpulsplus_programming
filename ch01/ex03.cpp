// 1장 연습문제 3

#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int a;
	int b;
	int c;

	cout << "첫 번째 변 : ";
	cin >> a;

	cout << "두 번째 변 : ";
	cin >> b;

	c = sqrt ( a * a + b * b );

	cout << "빗변 길이 : " << c << endl;

	return 0;
}