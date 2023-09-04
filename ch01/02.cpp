// 화씨온도를 섭씨온도로 바꾸기

// 화씨 온도를 섭씨 온도로 바꾸는 변환식 
// c_temp = (5.0 / 9.0) * (f_temp - 32)

#include <iostream>

using namespace std;

int main() {
	double f_temp = 60;
	double c_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);

	cout << "화씨온도 " << f_temp << "도는 섭씨온도" << c_temp << "도입니다." << endl;

	return 0;
}
