// �ߺ� �Լ�

#include <iostream>
using namespace std;

void print(int i) {
	cout << "���� ��� : " << i << endl;
}

void print(double f) {
	cout << "�Ǽ� ��� : " << f << endl;
}

void print(char c) {
	cout << "���� ��� : " << c << endl;
}

int main() {
	print(100);
	print(3.14);
	print('C');

	return 0;
}