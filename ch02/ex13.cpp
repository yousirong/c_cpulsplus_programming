// 2�� �������� 13
// ***

#include <iostream>
using namespace std;

int main() {
	int num;
	int temp;
	int a = 0;
	int b = 1;

	cout << "�� �ױ��� ���ұ�� : ";
	cin >> num;

	cout << a << " " << b << " ";

	for (int i = 2; i < num; i++) {
		temp = b;
		b = a + b;
		a = temp;

		cout << b << " ";
	}

	return 0;
}