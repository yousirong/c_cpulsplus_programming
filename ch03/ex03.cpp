// 3�� ��������

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

	cout << "���� �ﰢ���� �� �� : ";
	cin >> a;
	cout << "���� �ﰢ���� �� �� : ";
	cin >> b;
	
	cout << "���� : " << hypot(a, b) << endl;

	return 0;
	
}