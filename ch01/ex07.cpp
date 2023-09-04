// 1장 연습문제 7

#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159

int main() {
	float radius; // 반지름
		
	cout << "반지름 : ";
	cin >> radius;

	double surfaceArea = 4 * pi * radius * radius ;
	double volume = (4.0 / 3.0) * pi *pow(radius, 3);

	cout << "표면적 : " << surfaceArea << endl;
	cout << "부피: " << volume << endl;

	return 0;
}