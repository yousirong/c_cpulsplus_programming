// p99 범위 기반 for 루프

#include <iostream>
#include <string>
using namespace std;

int main() {
	int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i : list) {
		cout << i << " ";
	}

	cout << endl;
}