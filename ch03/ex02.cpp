// 3장 연습문제 2

#include <iostream>
using namespace std;

inline float calc_volume(float radius) {
	return 4.0 / 3.0 * 3.14 * pow(radius, 3);
}

int main() {

	float volume;

	cout << "반지름을 입력하시오 : ";
	cin >> volume;

	volume = calc_volume(volume);

	cout << "구의 부피는 " << volume << endl;
}

