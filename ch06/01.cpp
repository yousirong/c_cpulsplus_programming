// 여러 권의 책을 저장해보자

#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string name, int price) : title{ name }, price{ price } {}
	void print() {
		cout << "제목 : " << title << ", 가격 : " << price << endl;
	}
};

int main(void) {
	Book books[2] = { Book("어서와 C++은 처음이지!", 30000), Book("어서와 파이썬은 처음이지!", 22000) };

	cout << "소장하고 있는 책 정보 : " << endl;
	cout << "=======================================" << endl;
	for (Book& b : books)
		b.print();
	cout << "=======================================" << endl;
	return 0;
}