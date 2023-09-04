#include <iostream>
using namespace std;

int main() {
	double c_temp = 0;
	double f_temp;

	cout << "변환할 섭씨 온도를 입력하세요: ";
	cin >> c_temp;

	f_temp = (9.0 / 5.0 * c_temp) + 32;
	cout << "섭씨온도 " << c_temp << "도는 화씨온도 " << f_temp << "도입니다." << endl;

	return 0;
}
