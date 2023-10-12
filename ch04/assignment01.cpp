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
        return abs(a);
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
