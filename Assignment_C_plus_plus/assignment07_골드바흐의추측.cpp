#include <iostream>
#include <vector>

using namespace std;

bool check_prime(int n) {  // 소수 판별 함수
	if (n <2) // 2보다 적으면 false
		return false;
	
	for (int i=2; i*i<= n;++i) { //2부터 제곱근까지의 수로 
		if (n %i==0) //나누어 떨어지면
			return false;  //소수가 아니라고 판단
	}
	return true;
}

vector<int> gold_bach(int n) {
	vector<int> pr;
	for (int i =2;i<n; ++i) {//2부터 n-1까지의 수 중에서 소수인 수들을 primes 벡터에 저장
		if (check_prime(i))
			pr.push_back(i);
	}

	for (int pr1 :pr) { //for 반복문 이중 사용하여 가능한 세 소수 조합을 찾기
		for (int pr2 :pr) { //각각의 조합에서 첫 번째와 두 번째 소수를 더하고, 
			int pr3 = n-pr1- pr2;
			if (pr3 >=2&&check_prime(pr3)) { //그 결과값과 n을 비교하여 남은 값이 소수인 경우 조합으로 인정
				vector<int> result {pr1, pr2, pr3};
				return result; //조합이 발견되면 해당 조합을 벡터로 생성하여 반환
			}
		}
	}

	return {};//발견되지 않으면 빈 벡터를 반환
}

int main() {
	int user;

	cin >> user;

	vector<int> res=gold_bach(user); //gold_bach 함수를 호출

	if (!res.empty()){ //결과 값이 비어있지 않으면 세 소수를 출력
		for(int num:res)
			cout <<num<<" ";
	}
	else
		cout <<"false"; //결과 값이 비어있으면 "false"를 출력

	return 0;
}
/*
문제의 정의 : 
주어진 홀수 n에 대해 골드바흐 추측(세 개의 소수 합)을 찾아서 출력하는 기능을 구현함으로써 해결하는 문제

문제의 해결 방안 : 
 check_prime 함수: 주어진 숫자가 소수인지를 판별하는 함수입니다. n이 2보다 작거나, 2부터 제곱근까지의 수로 나누어 떨어지면 소수가 아니라고 판단합니다.
 
gold_bach 함수: 주어진 홀수 n에 대해 골드바흐의 추측을 적용하여 가능한 세 소수를 찾습니다. 먼저, 2부터 n-1까지의 수 중에서 소수인 수들을 primes 벡터에 저장합니다. 그런 다음, 이중 반복문을 사용하여 가능한 세 소수 조합을 찾습니다. 각각의 조합에서 첫 번째와 두 번째 소수를 더하고, 그 결과값과 n을 비교하여 남은 값이 소수인 경우 조합으로 인정합니다. 만약 조합이 발견되면 해당 조합을 벡터로 생성하여 반환하고, 발견되지 않으면 빈 벡터를 반환합니다.

main 함수: 사용자로부터 입력 값을 받아서 골드바흐의 추측을 적용하고 결과를 출력하는 부분입니다.
사용자로부터 홀수 값을 입력 받습니다.

입력 받은 값으로 gold_bach 함수를 호출하여 결과 값을 얻습니다.
결과 값이 비어있지 않으면 세 소수를 출력합니다.
결과 값이 비어있으면 "false"를 출력합니다.

*/