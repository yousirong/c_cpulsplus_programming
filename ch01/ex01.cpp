// 1장 연습문제 1

#include <string.h>
#include <iostream>

using namespace std;

int main() {
	string subject; // 주어
	string verb; // 동사
	string object; // 목적어

	cout << "주어 : ";
	cin >> subject;

	cout << "동사 : ";
	cin >> verb;

	cout << "목적어 : ";
	cin >> object;

	cout << endl << subject << " " << verb << " " << object << endl;

	return 0;
}
