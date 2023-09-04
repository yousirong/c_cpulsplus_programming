// 지뢰 찾기 

#include <iostream>
#include <time.h>
using namespace std;

int main() {
	bool board[10][10] = { 0 };
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((rand() % 100) < 30) // 30% 확률로 난수 생성, 지뢰 저장
				board[i][j] = true;
		}
	}

	// 게임판 출력
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j])
				cout << "# ";
			else
				cout << ". ";
		}
		cout << endl;
	}

	return 0;
}