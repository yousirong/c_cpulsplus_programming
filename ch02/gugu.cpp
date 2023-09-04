// p107 예제 1

#include <iostream>
using namespace std;

#define  WIDTH 9	// 열
#define HEIGHT 3	// 행

int main() {

	int table[HEIGHT][WIDTH];
	int r, c;

	for (r = 0; r < HEIGHT; r++)
		for (c = 0; c < WIDTH; c++)
			table[r][c] = (r + 1) * (c + 1);

	for (r = 0; r < HEIGHT; r++) {
		for (c = 0; c < WIDTH; c++) {
			cout << table[r][c] << ", ";
		}
		cout << endl;
	}
}