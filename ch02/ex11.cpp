// 2�� �������� 11

#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int n;

	cout << "n�� ���� �Է��Ͻÿ� : ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum += i * i;
	}

	cout << "��� ���� " << sum << "�Դϴ�. " << endl;

	return 0;
}