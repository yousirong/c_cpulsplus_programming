// 사과를 제일 좋아하는 사람 찾기

#include <iostream>
using namespace std;

int main() {
	
	const int SIZE = 10;
	int list[SIZE];
	int max, min, person;

	for (int& elem : list) {
		cout << "아침에 먹는 사과의 개수 : ";
		cin >> elem;
	}
	cout << endl;

	max = list[0];
	min = list[1];
	person = 0;

	for (int i = 1; i < SIZE; i++) {
		if (list[i] > max) {
			max = list[i];
			person = i;
		}
	}
	
	cout << "가장 많이 사과를 먹은 사람의 번호 : " << person+1 << endl;

	for (int i = 1; i < SIZE; i++) {
		if (list[i] < min) {
			min = list[i];
			person = i;
		}
	}

	cout << "가장 적게 사과를 먹은 사람의 번호 : " << person+1 << endl;

	return 0;
}