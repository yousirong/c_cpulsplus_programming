// 2�� �������� 5

#include <iostream>
#include <string>
using namespace std;

int main() {
	int num;
	int sum = 0;

	do {
		cout << "������ �Է��Ͻÿ� : ";
		cin >> num;
		sum += num;
	} while (num != 0);

	cout << "�հ� : " << sum << endl;

	return 0;
}