#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class LunarLander {
private :
	double x, y; // 현재 위치
	double velocity; // 속도
	double fuel; // 연료
	string status;
	Texture t1, t2; // 텍스처 객체
	Sprite spaceship, burst; // 스프라이트 객체
	Font font;
	Text text;
public :
	LunarLander(double h, double v, double f);
	bool checkLanded(); // 착륙 검사 함수
	void update(double rate); // 상태 업데이트 함수
	void draw(RenderWindow& window); // 착륙선을 그리는 함수
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
		cout << "폰트 파일을 오픈할 수 없음!!" << endl;
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