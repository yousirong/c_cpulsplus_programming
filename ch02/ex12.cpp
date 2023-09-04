// 2장 연습문제 12

#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			cout << "박수 ";
		}
		else
			cout << i << " ";
	}

	return 0;
}