// ����� ���� �����ϴ� ��� ã��

#include <iostream>
using namespace std;

int main() {
	
	const int SIZE = 10;
	int list[SIZE];
	int max, min, person;

	for (int& elem : list) {
		cout << "��ħ�� �Դ� ����� ���� : ";
		cin >> elem;
	}
	cout << endl;

	max = list[0];
	min = list[1];
	person = 0;

	for (int i = 1; i < SIZE; i++) {
		if (list[i] > max) {
			max = list[i];
			person = i;
		}
	}
	
	cout << "���� ���� ����� ���� ����� ��ȣ : " << person+1 << endl;

	for (int i = 1; i < SIZE; i++) {
		if (list[i] < min) {
			min = list[i];
			person = i;
		}
	}

	cout << "���� ���� ����� ���� ����� ��ȣ : " << person+1 << endl;

	return 0;
}