// �ִ� �ѵ��� ���� ���

#include <iostream>

using namespace std;

int main() {
	int money; // ���� ������ �ִ� ��
	int candy_price; // ĵ���� ����
	
	cout << "���� ������ �ִ� �� : ";
	cin >> money;
	cout << "ĵ���� ���� : " ;
	cin >> candy_price;
 
	// �ִ��� �� �� �ִ� ������ �� 
	int n_candies = money / candy_price;
	cout << "�ִ�� �� �� �ִ� ĵ���� ���� : " << n_candies << endl;

	// ������ �����ϰ� ���� ��
	int change = money % candy_price;
	cout << "ĵ�� ���� �� ���� �� : " << change << endl; 

	return 0;
}
