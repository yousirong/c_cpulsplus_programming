// 2�� �������� 4

#include <iostream>
using namespace std;

int main() {

	int number;
	int box[5] = { 0 };
	int i;

	for (i = 0; i < 5; i++) {
		cout << "������ �ټ��� �Է��մϴ�.";
		cin >> number;
		box[i] = number;
	}
	if (box[0] == 5 || box[1]==5 || box[2] == 5 || box[3] == 5 || box[4] == 5)
		cout << "5�� �Է��Ͽ�����! ��ǻ�� ��" << endl;
	else
		cout << "�γ����� ���մϴ�. ����� ��" << endl;

return 0;
}