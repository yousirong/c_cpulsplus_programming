// 2�� �������� 14

#include <iostream>
using namespace std;

int main() {
	char ch;

	cout << "������ ����(+,-,*,/) : ";
	cin >> ch;

	int x, y;
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> x >> y;
	
	switch (ch) {
	case '+':
		cout << "����� ��� : " << x + y << endl;
		break;
	case '-':
		cout << "����� ��� : " << x - y << endl;
		break;
	case '*':
		cout << "����� ��� : " << x * y << endl;
		break;
	case '/':
		if (y > 0)
			cout << "����� ��� : " << x / y << endl;
		else
			cout << "�и� 0�� ���� ����� �Ұ����մϴ�." << endl;
		break;
	}

	return 0;

}