// 2�� �������� 8

#include <iostream>
using namespace std;

int main() {

	int number;

	cout << "������ �Է��ϼ��� : ";
	cin >> number;
	
	for (int i = 1; i <= number; i++) {
		if (number % i == 0)
			cout << i << " ";
	}
	return 0;
}