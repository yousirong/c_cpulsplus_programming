// 1�� �������� 8
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int Q1;
	int Q2;
	int Q3;
	int middle;
	int final;

	cout << "���� #1 ���� : ";
	cin >> Q1;

	cout << "���� #2 ���� : ";
	cin >> Q2;

	cout << "���� #3 ���� : ";
	cin >> Q3;

	cout << "�߰���� ���� : ";
	cin >> middle;

	cout << "�⸻��� ���� : ";
	cin >> final;

	int total = Q1 + Q2 + Q3 + middle + final;

	cout << "==========================" << endl;
	cout << "���� ���� : " << total << endl;
	cout << "==========================" << endl;

	return 0;
}