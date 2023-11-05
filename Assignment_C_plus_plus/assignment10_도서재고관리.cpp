#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string Book_Num;  // 도서 번호
    string Book_Name;    // 도서 이름
    int Pr;          // 가격
    int Num;       // 수량

    Book() : Book_Num(""), Book_Name(""), Pr(0), Num(0) {}

    Book(const string& bNumber, const string& bName, int p, int q)
        : Book_Num(bNumber), Book_Name(bName), Pr(p), Num(q) {}

    void New_Book() {
        // 재고가 있는 도서 정보 출력
        if (Num > 0) {
            cout << Book_Num << " " << Book_Name << " " << Pr << " " << Num << endl;
        }
    }

    void Restock(int count) {
        // 도서 재고 증가
        Num += count;
    }

    void Sell(int count) {
        // 도서 판매
        if (count <= Num) {
            Num -= count;
        }
    }

    void Discard() {
        // 도서 폐기 (재고 수량을 0으로 설정)
        Num = 0;
    }
};

int main() {
    Book inventory[100];  // 도서 재고를 저장할 배열
    int inventoryCount = 0;  // 현재 재고 도서 수

    while (true) {
        char command;
        cin >> command;

        if (command == 'N') {
            // 신규 도서 입고
            string Book_Num, Book_Name;
            int Pr, Num;
            cin >> Book_Num >> Book_Name >> Pr >> Num;

            bool exists = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].Book_Num == Book_Num) {
                    exists = true;
                    break;
                }
            }

            if (!exists && inventoryCount < 100) {
                inventory[inventoryCount] = Book(Book_Num, Book_Name, Pr, Num);
                inventoryCount++;
            } else {
                cout << "error: 1" << endl; // 도서번호 중복 또는 재고 초과
            }
        } else if (command == 'R') {
            // 재고 도서 입고
            string Book_Num;
            int count;
            cin >> Book_Num >> count;

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].Book_Num == Book_Num) {
                    inventory[i].Restock(count);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "error: 2" << endl; // 도서번호를 찾을 수 없음
            }
        } else if (command == 'S') {
            // 재고 도서 판매
            string Book_Num;
            int count;
            cin >> Book_Num >> count;

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].Book_Num == Book_Num) {
                    inventory[i].Sell(count);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "error: 2" << endl; // 도서번호를 찾을 수 없음
            } else if (count > inventory[inventoryCount].Num) {
                cout << "error: 3" << endl; // 판매 수량 초과
            }
        } else if (command == 'D') {
            // 도서 폐기
            string Book_Num;
            cin >> Book_Num;

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].Book_Num == Book_Num) {
                    inventory[i].Discard();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "error: 2" << endl; // 도서번호를 찾을 수 없음
            }
        } else if (command == 'I') {
            // 도서 재고 상태 조회
            string Book_Num;
            cin >> Book_Num;

            bool found = false;
            for (int i = 0; i < inventoryCount; i++) {
                if (inventory[i].Book_Num == Book_Num) {
                    inventory[i].New_Book();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "error: 2" << endl; // 도서번호를 찾을 수 없음
            }
        } else if (command == 'P') {
            // 모든 도서의 재고 상태 조회
            for (int i = 0; i < inventoryCount; i++) {
                inventory[i].New_Book();
            }
        } else if (command == 'Q') {
            break; // 프로그램 종료
        }
    }

    return 0;
}

/*
문제의 정의 : 
서점의 도서 재고를 효과적으로 관리하려는 요구사항을 충족하는 프로그램을 개발해야 합니다.
프로그램은 다음 명령어를 처리해야 합니다:
N: 신규 도서 입고
R: 재고 도서 입고
S: 재고 도서 판매
D: 도서 폐기
I: 도서 재고 상태 조회
P: 모든 도서의 재고 상태 조회
L: 판매한 모든 도서의 판매 정보 조회
Q: 프로그램 종료
명령어에 따라 도서 정보를 관리하고, 오류 조건에 대한 메시지를 출력해야 합니다.
문제의 해결 방안 : 
Book 클래스를 정의하여 도서 정보를 관리합니다. 이 클래스는 도서 번호, 도서 이름, 가격, 수량을 저장하는 멤버 변수와 관련 동작을 수행하는 메서드를 포함합니다.

도서 정보는 Book 객체 배열로 관리됩니다. 최대 100권의 도서 정보를 저장할 수 있습니다.

주요 명령어(N, R, S, D, I, P, L, Q)에 대한 처리 함수를 작성합니다. 이 함수는 Book 객체 배열을 조작하고 결과를 출력합니다.

각 명령어에 대한 오류 조건(예: 도서 중복, 재고 부족)에 대한 메시지를 출력하여 사용자에게 알려줍니다.

주어진 명령어에 따라 도서 정보를 변경하거나 조회하며, 명령어에 따라 프로그램을 종료합니다.
*/