// 3�� �������� 2

#include <iostream>
using namespace std;

inline float calc_volume(float radius) {
	return 4.0 / 3.0 * 3.14 * pow(radius, 3);
}

int main() {

	float volume;

	cout << "�������� �Է��Ͻÿ� : ";
	cin >> volume;

	volume = calc_volume(volume);

	cout << "���� ���Ǵ� " << volume << endl;
}

