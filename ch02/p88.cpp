// ���� ���߱� ����
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));

	int answer = rand() % 100; // ���� ������ ���� ���� ����
	int guess; // ������� ��
	int tries = 0;

	do {
		cout << "������ �����غ����� : ";
		cin >> guess;
		tries++;

		if (guess < answer) 
			cout << "������ �������� �����ϴ�.";
		if (guess > answer)
			cout << "������ �������� �����ϴ�.";

	} while (answer != guess);

	cout << "�����Դϴ�. �õ� Ƚ�� : " << tries << "  ���� : " << answer << endl;

	return 0;
}