// p96 ����1
#include <iostream>
using namespace std;

int main() {
	const int STUDENTS = 10;
	int scores[STUDENTS]; // �迭 ����
	int sum = 0;
	int i, average;

	for (i = 0; i < STUDENTS; i++) {
		cout << "�л����� ������ �Է��Ͻÿ�: ";
		cin >> scores[i];
	}

	for (i = 0; i < STUDENTS; i++) {
		sum += scores[i];
	}
	average = sum / STUDENTS;
	cout << "���� ���: " << average << endl;

	return 0;
}