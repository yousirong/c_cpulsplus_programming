// 1�� �������� 3

#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int a;
	int b;
	int c;

	cout << "ù ��° �� : ";
	cin >> a;

	cout << "�� ��° �� : ";
	cin >> b;

	c = sqrt ( a * a + b * b );

	cout << "���� ���� : " << c << endl;

	return 0;
}