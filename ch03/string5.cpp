// p152

#include <iostream>
#include <string>
using namespace std;

int main() {
	string list[] = { "����", "�Ϸ�", "����" };

	for (auto& x : list)
		cout << (x + "�� �ȳ�!") << endl;
	return 0;
}