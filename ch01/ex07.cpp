// 1�� �������� 7

#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159

int main() {
	float radius; // ������
		
	cout << "������ : ";
	cin >> radius;

	double surfaceArea = 4 * pi * radius * radius ;
	double volume = (4.0 / 3.0) * pi *pow(radius, 3);

	cout << "ǥ���� : " << surfaceArea << endl;
	cout << "����: " << volume << endl;

	return 0;
}