// 2장 연습문제 9

#include <iostream>
using namespace std;

int main() {
	float f;
	float c;

	for (f = 0; f <= 100; f += 10) {
		c = (f - 32.0) * 5.0 / 9.0;
		cout << f << "\t" << c << endl;
	}

	return 0;
}