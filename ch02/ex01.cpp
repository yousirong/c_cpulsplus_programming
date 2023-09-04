// 2장 연습문제 1

#include <iostream>
using namespace std;

int main() {
	
	string s1;
	string s2;

	cout << "첫 번째 문자열 : ";
	cin >> s1;

	cout << "두 번째 문자열 : ";
	cin >> s2;

	if (s1 == s2)
		cout << "2개의 문자열이 같습니다.";
	else
		cout << "2개의 문자열이 다릅니다.";

	return 0;
}