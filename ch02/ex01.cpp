// 2�� �������� 1

#include <iostream>
using namespace std;

int main() {
	
	string s1;
	string s2;

	cout << "ù ��° ���ڿ� : ";
	cin >> s1;

	cout << "�� ��° ���ڿ� : ";
	cin >> s2;

	if (s1 == s2)
		cout << "2���� ���ڿ��� �����ϴ�.";
	else
		cout << "2���� ���ڿ��� �ٸ��ϴ�.";

	return 0;
}