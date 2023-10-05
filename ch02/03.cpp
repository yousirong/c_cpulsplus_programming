// Tic-Tac-Toe 게임

#include <iostream>
using namespace std;

int main() {

	char board[3][3]; // 보드 정의
	int x, y, k, i;

	// 보드 초기화
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	// 사용자로부터 위치를 받아 보드에 표시
	for (k = 0; k < 9; k++) {

		cout << "(x,y) 좌표 : ";
		cin >> x >> y;

		// 현재의 순번에 따라 'X', 'O' 중 선택
		board[x][y] = (k % 2 == 0) ? 'X' : 'O';
	
		//화면에 보드 그리기
		for (i = 0; i < 3; i++) {
			cout << "---|---|---|" << endl;
			cout << board[i][0] << "  |  " << board[i][1] << "|  " << board[i][2] << "|  " << endl;
		}

		cout << "---|---|---|" << endl;

		cout << "\n" << endl;
	}

	return 0;

}
