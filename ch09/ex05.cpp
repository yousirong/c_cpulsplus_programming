// 9장 연습문제 5

#include <iostream>
using namespace std;

class Box {
private:
	double length;
	double width;
	double height;
public:
	static int count;
	Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		length = l;
		width = h;
		height = h;
		count++;
	}
	double Volume() {
		return length * width * height;
	}
	static int getCount() {
		return count;
	}
};

int Box::count = 0;

int main() {
	Box box;
	cout << "전체 객체 수 : ";
	cout << box.count;
	return 0;
}
