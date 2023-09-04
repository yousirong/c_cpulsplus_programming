// p 326

#include <iostream>
using namespace std;

void f(char* p) {
	cout << "f(char *)" << endl;
}

void f(int i) {
	cout << "f(int)" << endl;
}

int main() {
	f(nullptr);
	return 0;
}



