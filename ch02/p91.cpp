// ������ ���� ����ϱ�
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int choice;

	cout << "������ �����ϼ���(1, 2, 3) : ";
	cin >> choice;

	int length;
	int width;
	int radius;

	if (choice == 1) {
		cout << "���� : ";
		cin >> width;
		cout << "���� : ";
		cin >> length;

		int area = width * length;
		cout << "���� : " << area << endl;
	} else if (choice == 2) {
		cout << "������ : ";
		cin >> radius;
		
		double area = (double)radius * radius * 3.14;
		cout << "���� : " << area << endl;
	} else if (choice == 3) {
		cout << "���� : ";
		cin >> width;
		cout << "���� : ";
		cin >> length;

		int area = (width * length) / 2;
		cout << "���� : " << area << endl;
	} else
		cout << "�ùٸ��� ���� �����Դϴ�." << endl;

	return 0;
}