// 1�� �������� 4

#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int L;
	int W;
	int H;

	cout << "���� : ";
	cin >> L;

	cout << "�ʺ� : ";
	cin >> W;

	cout << "���� : ";
	cin >> H;

	int volume; // ����
	int surfaceArea; // ǥ����

	volume = L * W * H;
	surfaceArea = 2 * ((L * W) + (L * H) + (H * W));

	cout << endl;
	cout << "������ ���� : " << volume << endl;
	cout << "������ ǥ���� : " << surfaceArea << endl;

	return 0;
}