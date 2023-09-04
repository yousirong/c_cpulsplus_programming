// 배열에서 최대값 찾기

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int list[10];
	int max;

	for (int& elem : list) {
		elem = rand() % 100 + 1; // 1부터 100 사이의 난수 생성
		cout << elem << " ";
	}

	cout << endl;

	max = list[0]; // 첫 번째 원소를 최대값으로 가정
	for (auto& elem : list) {
		if (elem > max)
			max = elem;
	}
	cout << "최대값 : " << max << endl;
	return 0;
}