// 3�� �������� 1

#include <iostream>
using namespace std;

int maximum(int x, int y, int z) {
	
	if (x > y && x > z)
		return x;
	else if (y > x && y > z)
		return y;
	else
		return z;
}

int main() {
	int a, b, c;

	cout << "�� ���� ������ �Է��Ͻÿ� : ";
	cin >> a >> b >> c;
	
	int maxNum = maximum(a, b, c);

	cout << "���� ū ������ " << maxNum << endl;

	return 0;
}

