// 2장 연습문제 10

#include <iostream>
using namespace std;

int main() {

	int a, b, c;
	
	for (a = 1; a < 100; a++) {
		for (b = 1; b < 100; b++) {
			for (c = 1; c < 100; c++) {
				if (c * c == a * a + b * b)
					cout << a << " " << b << " " << c << endl;
			}
		}
	}

	return 0;
}