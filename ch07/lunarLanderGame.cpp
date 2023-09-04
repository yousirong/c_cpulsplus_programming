#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class LunarLander {
private :
	double x, y; // ���� ��ġ
	double velocity; // �ӵ�
	double fuel; // ����
	string status;
	Texture t1, t2; // �ؽ�ó ��ü
	Sprite spaceship, burst; // ��������Ʈ ��ü
	Font font;
	Text text;
public :
	LunarLander(double h, double v, double f);
	bool checkLanded(); // ���� �˻� �Լ�
	void update(double rate); // ���� ������Ʈ �Լ�
	void draw(RenderWindow& window); // �������� �׸��� �Լ�
};

LunarLander::LunarLander(double h, double v, double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/burst.png");
	spaceship.setTexture(t1);
	burst.setTexture(t2);
	spaceship.setPosition(x, y);
	burst.setPosition(x + 20, y + 50);
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "��Ʈ ������ ������ �� ����!!" << endl;
	}
	text.setFont(font);
}

bool LunarLander::checkLanded() {
	if (y <= 0)
		return true;
	return false;
}

void LunarLander::update(double amount) {
	if (fuel <= 0) {
		fuel = 0;
		amount = 0;
	}
	fuel = fuel - amount;
	velocity = velocity = amount + 0.8;
	y = y + velocity;
	if (y > 450) 
		y = 450;
	spaceship.setPosition(x, y);
	burst.setPosition(x + 20, y + 50);
	status = "Press up Key!\nheight : " + to_string(y) + "\nspeed : " + to_string(velocity) + "\nfuel : " + to_string(fuel);
}

void LunarLander::draw(RenderWindow& window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}

int main() {
	RenderWindow window(VideoMode(600, 480), "LUNAR LANDER");
	window.setFramerateLimit(60);

	Texture t;
	Sprite background;
	t.loadFromFile("images/background.png");
	background.setTexture(t);

	LunarLander lander(300.0, 1.0, 100.0);
	while(window.isOpen()) {
		Event e;
		
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up))
			lander.update(3.0);
		else
			lander.update(0.0);

		window.clear();
		window.draw(background);
		lander.draw(window);

		window.display();
		Sleep(100);
	}
	return 0;
}