// ��� ���� �ڵ� ����
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	int answer;

	cout << "��� ������ �����մϴ�." << endl;

	while (true) {
		int x = rand() % 100;
		int y = rand() % 100;
		cout <<endl<< x << "+" << y << " = ";
		cin >> answer;
		if (answer == (x + y))
			cout << "�����Դϴ�." << endl;
		else
			cout << "�����Դϴ�. ������ " << x + y << endl;
	}
	return 0;
}