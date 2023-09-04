// 세 개의 정수 중에서 큰 수 찾기
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int largest;

	cout << "세 개의 정수를 입력하세요 : ";
	cin >> a >> b >> c;

	if (a > b && a > c)
		largest = a;
	else if (b > a && b > c)
		largest = b;
	else
		largest = c;

	cout << "가장 큰 정수는 " << largest << "입니다." << endl;

	return 0;
}
