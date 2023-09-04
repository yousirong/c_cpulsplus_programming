// swap() 함수 

#include <iostream>
using namespace std;

void swap(int& x, int& y) {
	int tmp;

	tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int a = 100; 
	int b = 200;

	printf("a = %d  b = %d\n", a, b);
	swap(a, b);
	printf("a = %d  b = %d\n", a, b);
	return 0;
}
