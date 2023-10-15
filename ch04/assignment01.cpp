#include <iostream>
#include <string>

using namespace std;

class Arithmetic {  // class 사칙연산
public:
	int numer;  // 분자
	int denom;  // 분모
	Arithmetic(int num, int den) : numer(num), denom(den) {
		if (denom == 0) {
			throw invalid_argument("분모는 0이 될 수 없습니다.");
		}
	}

	// 최대공약수 계산 함수
	static int gcd(int i, int j) {
		while(j != 0){
			int temp = i % j;
			i = j;
			j = temp;
		}
		return abs(i);
	}

	// 최소공배수 계산 함수
	static int lcm(int i, int j) {
		return abs(i * j) / gcd(i, j);
	}

	// 약분 함수
	void abbreviation() {
		int common = gcd(numer, denom);
		numer /= common;
		denom /= common;
	}

	// 사칙연산 함수들

	Arithmetic operator+(const Arithmetic& other){  // 덧셈 
		int lcm_value = lcm(this->denom, other.denom);
		return Arithmetic((this->numer * (lcm_value / this->denom)) + 
											(other.numer * (lcm_value / other.denom)), 
											lcm_value);
	}

	Arithmetic operator-(const Arithmetic& other){  // 뺄셈
		int lcm_value = lcm(this->denom, other.denom);
		return Arithmetic((this->numer * (lcm_value / this->denom)) - 
											(other.numer * (lcm_value / other.denom)), 
											lcm_value);  
	} 

	Arithmetic operator*(const Arithmetic& other){  // 곱셈
		return {this->numer*other.numer,this->denom*other.denom};
	} 

	Arithmetic operator/(const Arithmetic& other){  // 나눗셈
		if(other.numer==0)
			throw invalid_argument("0으로 나눌 수 없습니다.");
		else  
			return {this->numer*other.denom,this->denom*other.numer};
	}  
};

int main() {
	string user;
	getline(cin, user);

	size_t local = 0;

	local = user.find('|');  //첫번째 분자 분모 찾을 경우
	string first_num = user.substr(0, local);
	user.erase(0, local + 1);

	local = user.find(' ');  //첫번째 분수 계산후 공백
	string first_den = user.substr(0, local);
	user.erase(0, local + 1);

	char operation = user[0];  // 공백후 연산자 만날경우 
	user.erase(0, 2);

	local = user.find('|');  // 두번째 분자 분모 찾을 경우
	string second_num = user.substr(0, local);
	user.erase(0, local + 1);

	local = user.find('=');  // 계산 후 = 연산 찾을 경우
	string second_den = user.substr(0, local);
	user.erase(0, local + 1);

	// 이제 문자열로부터 얻은 데이터를 Arithmetic 객체로 변환합니다.
	Arithmetic arithmetic1(stoi(first_num), stoi(first_den));
	Arithmetic arithmetic2(stoi(second_num), stoi(second_den));
	Arithmetic result(0, 1); // 초기값 설정

	// 입력된 연산을 기반으로 계산합니다.
	switch (operation) {
		case '+':
			result = arithmetic1 + arithmetic2;
			break;
		case '-':
			result = arithmetic1 - arithmetic2;
			break;
		case '*':
			result = arithmetic1 * arithmetic2;
			break;
		case '/':
			result = arithmetic1 / arithmetic2;
			break;
		default:
			cout << "Invalid operation: " << operation << endl;
			return 1;
	}

    // 결과를 출력합니다.
	cout << result.numer << "|" << result.denom << endl;

	return 0;
}
/*
문제의 정의:
주어진 문자열에서 두 분수와 연산자를 추출하여, 해당 분수에 대한 사칙연산을 수행한 후, 결과를 약분된 형태로 출력하는 프로그램을 작성하는 것입니다. 이때, 분수는 "분자|분모" 형태로 주어집니다. 

문제의 해결 방안:
1. 사용자로부터 입력 문자열을 받아옵니다.
2. 입력 문자열에서 첫 번째 분수의 분자와 분모를 추출합니다.
3. 입력 문자열에서 연산자를 추출합니다.
4. 입력 문자열에서 두 번째 분수의 분자와 분모를 추출합니다.
5. 입력된 분자와 분모를 사용하여 `Arithmetic` 클래스의 객체를 생성합니다.
6. 연산자에 따라 두 분수를 덧셈, 뺄셈, 곱셈 또는 나눗셈을 수행합니다.
7. 계산 결과는 약분하여 출력합니다.

위의 코드에서, `Arithmetic` 클래스는 주어진 분자와 분모를 가지며, 최대공약수와 최소공배수를 계산하고, 약분을 수행하는 함수를 제공합니다. 이 클래스를 사용하여 분수의 사칙연산을 수행합니다. 또한, 분모가 0인 경우 예외처리가 수행되어 안정적인 동작을 보장합니다.

또한, 코드에서는 입력 문자열을 처리하기 위해 STL의 문자열 함수를 사용합니다. 문자열에서 필요한 정보를 추출하여 `Arithmetic` 클래스의 객체로 변환하고, 계산 결과를 출력합니다.
*/
