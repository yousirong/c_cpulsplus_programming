// 2�� �������� 15

#include <iostream>
#include <time.h>
using namespace std;

int main() {

	srand(time(NULL));

	int computerChoice = rand() % 3 + 1;

	int userChoice;

	cout << "����, ����, �� �߿� �ϳ��� �����Ͻÿ�(1=����, 2=����, 3=��) : ";
	cin >> userChoice;
	
	cout << "����� ���� : ";
	switch (userChoice) {
	case 1: cout << "����";
		break;
	case 2: cout << "����";
		break;
	case 3: cout << "��";
		break;
	default: cout << "�ùٸ��� ���� �����Դϴ�.";
		break;
	}

	cout << endl << "��ǻ�� : ";
	switch (computerChoice) {
	case 1: cout << "����" << endl;
		if (userChoice == 2)
			cout << "����� ��!" << endl;
		else if (userChoice == 3)
			cout << "����� ��!" << endl;
		else cout << "�����ϴ�!" << endl;
		break;

	case 2: cout << "����" << endl;
		if (userChoice == 1)
			cout << "����� ��!" << endl;
		else if (userChoice == 3)
			cout << "����� ��!" << endl;
		else cout << "�����ϴ�!" << endl;
		break;

	case 3: cout << "��" << endl;
		if (userChoice == 2)
			cout << "����� ��!" << endl;
		else if (userChoice == 1)
			cout << "����� ��!" << endl;
		else cout << "�����ϴ�!" << endl;
		break;
	}

	return 0;

}