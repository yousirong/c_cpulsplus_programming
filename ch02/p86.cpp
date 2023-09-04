// 자음과 모음 개수 세기
#include <iostream>
using namespace std;

int main() {
	int vowel = 0; // 모음
	int consonant = 0; // 자음

	char ch;

	cout << "영문자를 입력하고 ctrl-Z 를 누르세요" << endl;

	while (cin >> ch) {
		switch (ch) {
		case 'a':
		case 'i':
		case 'u':
		case 'e':
		case 'o':
			vowel++;
			break;
		default :
			consonant++;
			break;
		}
	}

	cout << "모음 : " << vowel << endl;
	cout << "자음 : " << consonant << endl;

	return 0;
}