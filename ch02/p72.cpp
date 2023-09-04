// 비밀 코드 맞추기
#include <iostream>
using namespace std;

int main() {
	char secret_code = 'h';
	char code;

	cout << "비밀코드를 맞춰보세요 : ";
	cin >> code;

	if (code < secret_code)
		cout << code << "보다 뒤에 있음" << endl;
	else if (code > secret_code)
		cout << code << "보다 앞에 있음" << endl;
	else
		cout << "정답입니다." << endl;

	return 0;
}
