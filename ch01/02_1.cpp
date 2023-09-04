#include <iostream>
using namespace std;

int main() {
	double c_temp = 20;
	double f_temp;

	f_temp = (9.0 / 5.0 * c_temp) + 32;

	cout << "섭씨온도 " << c_temp << "도는 화씨온도 " << f_temp << "도입니다." << endl;

	return 0;
}
