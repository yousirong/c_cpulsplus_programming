// p188

#include <iostream>
#include <string>
using namespace std;

class PrintData {
public:
	void print(int i) {
		cout << i << endl;
	}
	void print(double f) {
		cout << f << endl;
	}
	void print(string s = "No Data!") {
		cout << s << endl;
	}
};

int main() {
	PrintData obj;

	obj.print(4);
	obj.print(3.14);
	obj.print("C++14 is cool!");
	obj.print();

	return 0;
}