// 원들의 경주 게임

#include <iostream>
#include <windows.h>
using namespace std;

class Circle {
public:
	Circle(int xval, int yval, int r);
	void draw();
	void move();
private:
	int x, y, radius;
};

Circle::Circle(int xval, int yval, int r) 
	: x{xval}, y{yval}, radius{r} {
}

void Circle::draw() {
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

void Circle::move() {
	x += rand() % 50;
}

int main() {
	Circle c1{ 100,100,50 };
	Circle c2{ 100,200,40 };

	for (int i = 0; i < 20; i++) {
		c1.move();
		c1.draw();

		c2.move();
		c2.draw();
		Sleep(1000);
	}
	return 0;
}
