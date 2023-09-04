// 사각형은 클래스로 나타내자

#include <iostream>
using namespace std;

class Rectangle {
public :
	int width, height;
	int calcArea() {
		return width * height;
	}
};

int main() {
	Rectangle obj;

	obj.width = 3;
	obj.height = 4;
	int area = obj.calcArea();

	cout << "사각형의 넒이 : " << area << endl;

	return 0;
}
