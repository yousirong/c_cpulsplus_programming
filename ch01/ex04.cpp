// 1장 연습문제 4

#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int L;
	int W;
	int H;

	cout << "길이 : ";
	cin >> L;

	cout << "너비 : ";
	cin >> W;

	cout << "높이 : ";
	cin >> H;

	int volume; // 부피
	int surfaceArea; // 표면적

	volume = L * W * H;
	surfaceArea = 2 * ((L * W) + (L * H) + (H * W));

	cout << endl;
	cout << "상자의 부피 : " << volume << endl;
	cout << "상자의 표면적 : " << surfaceArea << endl;

	return 0;
}