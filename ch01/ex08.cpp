// 1장 연습문제 8
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int Q1;
	int Q2;
	int Q3;
	int middle;
	int final;

	cout << "퀴즈 #1 성적 : ";
	cin >> Q1;

	cout << "퀴즈 #2 성적 : ";
	cin >> Q2;

	cout << "퀴즈 #3 성적 : ";
	cin >> Q3;

	cout << "중간고사 성적 : ";
	cin >> middle;

	cout << "기말고사 성적 : ";
	cin >> final;

	int total = Q1 + Q2 + Q3 + middle + final;

	cout << "==========================" << endl;
	cout << "성적 총합 : " << total << endl;
	cout << "==========================" << endl;

	return 0;
}