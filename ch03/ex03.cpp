// 3장 연습문제

#include <iostream>
#include <string>
using namespace std;

double hypot(double a, double b) {
	double c = sqrt(a * a + b * b);
	return c;
}

int main() {

	double a;
	double b;

	cout << "직각 삼각형의 한 변 : ";
	cin >> a;
	cout << "직각 삼각형의 한 변 : ";
	cin >> b;
	
	cout << "빗변 : " << hypot(a, b) << endl;

	return 0;
	
}