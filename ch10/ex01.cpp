// 10장 연습문제 1

#include <iostream>
#include <string>
using namespace std;

class Box {
private :
	double length;
	double width;
	double height;
public :
	Box(int l = 0, int w = 0, int h = 0) 
		: length { l }, width { w }, height { h } { }

	double getVolume(void) {
		return length * width * height;
	}
	Box operator+(const Box& box);
};

Box Box::operator+(const Box& box) {
	Box b;
	b.length = this->length + box.length;
	b.height = this->height + box.height;
	b.width = this->width + box.width;

	return b;
}

int main() {
	Box a(10, 10, 10), b(20, 20, 20);
	Box c = a + b;

	cout << "상자 #1" << endl;
	cout << "상자의 길이 : " << endl;
	cout << "상자의 너비 : " << endl;
	cout << "상자의 높이 : " << endl;
	cout << "상자의 부피 : " << a.getVolume << endl;

	cout << "상자 #2" << endl;
	cout << "상자의 길이 : " << endl;
	cout << "상자의 너비 : " << endl;
	cout << "상자의 높이 : " << endl;
	cout << "상자의 부피 : " << b.getVolume << endl;

	cout << "상자 #3" << endl;
	cout << "상자의 길이 : " << endl;
	cout << "상자의 너비 : " << endl;
	cout << "상자의 높이 : " << endl;
	cout << "상자의 부피 : " << c.getVolume << endl;

	return 0;
	
 }
