#include <iostream>
#include <string>
using namespace std;

bool inter_palin(const string& eng) {  // 좌우동형 검사해주는 함수
	int fir = 0;  // 첫번째 문자 검사
	int lst = eng.length() - 1; // 마지막 문자 검사 

	while (fir < lst) {  // 처음과 마지막을 검사를 시작으로 
			if (eng[fir] != eng[lst]) {  // 각위치의 문자가 같은지 검사
					return false;  // 틀리면 false 반환
				}
			fir++;  // 시작 문자 인덱스 +1
			lst--;  // 마지막 문자 인덱스 -1 
		}
	return true;  // 중간 인덱스에서 수렴 -> 이상없을 경우 true 반환
}

int main() {
	string user;
			// 사용자 문자열 입력 
	cin >> user;
			// 좌우동형 검사
	bool res = inter_palin(user);

	// 결과 출력
	if(res)
		cout << user << " is a palindrome." << endl;
	else 
		cout << user << " is NOT a palindrome." <<endl;

   return 0;
}

/*
문제의 정의 : 팰린드롬 검사하는 함수를 작성하여 사용자로부터 입력 받은 문자의 인덱스를 일치하는지 검사하는 문제입니다.

문제의 해결 방안 : 
이 프로그램은 inter_palin 함수를 사용하여 주어진 문자열이 좌우동형인지 확인합니다. 
제가 작성한 함수는  시작과 끝 인덱스를 추적하면서 각 위치의 문자가 일치하는지 확인합니다. 
만약 어떤 시점에서라도 각각 문자가 일치하지 않으면, 함수는 false를 반환하며,
그렇지 않으면 모든 쌍의 문자가 검사된 후에 true를 반환하게 해줍니다.

main 함수에서는 사용자로부터 문자열을 입력을 받고, 이것이 좌우동형인지 확인한 다음 결과를 출력합니다.
*/
