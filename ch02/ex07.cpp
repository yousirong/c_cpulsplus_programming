// 2장 연습문제 7

#include <iostream>
using namespace std;

int main() {

	for (int num = 1; num <= 100; num++) {
		if (num % 3 == 0)
			cout << num << " ";
	}
	return 0;
}