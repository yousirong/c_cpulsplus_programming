// 2�� �������� 5

#include <iostream>
#include <string>
using namespace std;

void sayHello(int n=1) {
	for (int i = 0; i < n; i++) {
		cout << "Hello ";
	}
}

int main() {

	int n;
	cout << "�ݺ� Ƚ���� �Է��ϼ��� : ";
	cin >> n;
	cout << "sayHello(" << n << ") -> ";
	for (int i = 0; i < n; i++) {
		if (true)
			 sayHello();
	}
	return 0;
}