// 2�� �������� 2

#include <iostream>
using namespace std;

int main() {
	
	int drinkNumber;

	cout << "�ݶ�, ��, ��������Ʈ, �ֽ�, Ŀ�� �߿��� �ϳ��� �����ϼ��� : ";
	cin >> drinkNumber;
	switch (drinkNumber) {
	case 1:
		cout << "�ݶ� �����߽��ϴ�."; 
		break;
	case 2:
		cout << "���� �����߽��ϴ�."; 
		break;
	case 3:
		cout << "��������Ʈ�� �����߽��ϴ�."; 
		break;
	case 4:
		cout << "�ֽ��� �����߽��ϴ�."; 
		break;
	case 5:
		cout << "Ŀ�Ǹ� �����߽��ϴ�."; 
		break;
	default:
		cout << "����. ������ ��ȿ���� �ʽ��ϴ�. ���� ��ȯ�մϴ�."; 
		break;
	}
	return 0;
}