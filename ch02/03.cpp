// Tic-Tac-Toe ����

#include <iostream>
using namespace std;

int main() {

	char board[3][3]; // ���� ����
	int x, y, k, i;

	// ���� �ʱ�ȭ
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	// ����ڷκ��� ��ġ�� �޾� ���忡 ǥ��
	for (k = 0; k < 9; k++) {

		cout << "(x,y) ��ǥ : ";
		cin >> x >> y;

		// ������ ������ ���� 'X', 'O' �� ����
		board[x][y] = (k % 2 == 0) ? 'X' : 'O';
	
		//ȭ�鿡 ���� �׸���
		for (i = 0; i < 3; i++) {
			cout << "---|---|---|" << endl;
			cout << board[i][0] << "  |  " << board[i][1] << "|  " << board[i][2] << "|  " << endl;
		}

		cout << "---|---|---|" << endl;

		cout << "\n" << endl;
	}

	return 0;

}
