// 주사위 게임
// 2개의 주사위를 던져서 주사위의 합을 표시하는 프로그램

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL)); // 매번 seed를 변경하여 난수 생성

	int dice1 = (rand() % 6) + 1;
	int dice2 = (rand() % 6) + 1;

	cout << "두 주사위의 합 : " << dice1 + dice2 << endl;

	return 0;
}
