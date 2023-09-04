// 도형 예제 #2

#include <iostream>
#include <windows.h>
using namespace std;

class Shape {
protected:
	int x, y;
public:
	Shape(int x, int y) : x(x), y(y) {}
	virtual void draw() {
		cout << "Shape Draw" << endl;
	}
};

class Rect : public Shape {
private:
	int width, height;
public:
	Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}
	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Rectangle(hdc, x, y, x + width, y + height);
	}
};

class Circle : public Shape {
private:
	int radius;
public:
	Circle(int x, int y, int r) : Shape(x, y), radius(r) {}
	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	}
};

int main() {
	Shape* shapes[3];
	shapes[0] = new Rect(rand() % 600, rand() % 300, rand() % 100, rand() % 100);
	shapes[1] = new Circle(rand() % 600, rand() % 300, rand() % 100);
	shapes[2] = new Circle(rand() % 600, rand() % 300, rand() % 100);

	for (int i = 0; i < 3; i++)
		shapes[i]->draw();
}
