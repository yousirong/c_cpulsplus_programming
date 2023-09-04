// p152

#include <iostream>
#include <string>
using namespace std;

int main() {
	string list[] = { "가현", "하령", "려현" };

	for (auto& x : list)
		cout << (x + "아 안녕!") << endl;
	return 0;
}