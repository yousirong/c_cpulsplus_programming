// 숫자 맞추기 게임
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));

	int answer = rand() % 100; // 난수 생성을 통해 정답 생성
	int guess; // 사용자의 답
	int tries = 0;

	do {
		cout << "정답을 추측해보세요 : ";
		cin >> guess;
		tries++;

		if (guess < answer) 
			cout << "제시한 정수보다 높습니다.";
		if (guess > answer)
			cout << "제시한 정수보다 낮습니다.";

	} while (answer != guess);

	cout << "정답입니다. 시도 횟수 : " << tries << "  정답 : " << answer << endl;

	return 0;
}