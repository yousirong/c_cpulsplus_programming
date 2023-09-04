// 3장 연습문제 4

#include <iostream>
#include <string>
using namespace std;

bool prime(int n) {
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) {
			return false;
		}
		else
			return true;
	}
}

int main() {

	for (int i = 2; i <= 100; i++)
		if (prime(i))
			cout << i << " ";

	return 0;
	
}