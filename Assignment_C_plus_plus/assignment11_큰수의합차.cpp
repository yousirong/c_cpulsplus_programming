#include <iostream>
#include <cstring>

using namespace std;

// 문자열을 배열에 저장하고 덧셈 연산을 수행하는 함수
string addStrings(string str1, string str2) {
    int line1 = str1.length();
    int line2 = str2.length();
    int res_line = max(line1, line2) + 1; // 결과 문자열의 길이
    char result[res_line + 1]; // 결과를 저장할 배열

    // 문자열을 배열에 역순으로 저장
    char* rev_line = new char[line1];
    char* rev_line2 = new char[line2];
    strcpy(rev_line, str1.c_str());
    strcpy(rev_line2, str2.c_str());

    int carry = 0; // 올림값 초기화
    int i = line1 - 1, j = line2 - 1, k = res_line; // 배열의 인덱스

    result[res_line] = '\0'; // 문자열 끝 마킹

    // 끝부터 시작하여 덧셈 연산 수행
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += (rev_line[i] - '0');
            i--;
        }
        if (j >= 0) {
            sum += (rev_line2[j] - '0');
            j--;
        }
        carry = sum / 10;
        result[--k] = (sum % 10) + '0';
    }

    // 결과 문자열 생성
    string sum_str(&result[k]);

    delete[] rev_line;
    delete[] rev_line2;

    return sum_str;
}

// 문자열을 배열에 저장하고 뺄셈 연산을 수행하는 함수
string subtractStrings(string str1, string str2) {
    int line1 = str1.length();
    int line2 = str2.length();
    int len = max(line1, line2); // 결과 문자열의 길이
    char result[len + 1]; // 결과를 저장할 배열

    // 문자열을 배열에 역순으로 저장
    char* rev_line = new char[line1];
    char* rev_line2 = new char[line2];
    strcpy(rev_line, str1.c_str());
    strcpy(rev_line2, str2.c_str());

    int borrow = 0; // 빌림값 초기화
    int i = line1 - 1, j = line2 - 1, k = len; // 배열의 인덱스

    result[len] = '\0'; // 문자열 끝 마킹

    // 끝부터 시작하여 뺄셈 연산 수행
    while (i >= 0 || j >= 0) {
        int sub = borrow;
        if (i >= 0) {
            sub += (rev_line[i] - '0');
            i--;
        }
        if (j >= 0) {
            sub -= (rev_line2[j] - '0');
            j--;
        }
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[--k] = sub + '0';
    }

    // 결과 문자열 생성
    string sub_str(&result[k]);

    delete[] rev_line;
    delete[] rev_line2;

    return sub_str;
}

int main() {
    string A, B;
    
    // 두 큰 정수를 문자열로 입력받음
    cin >> A >> B;

    // 덧셈과 뺄셈 연산 수행
    string sum = addStrings(A, B);
    string sub = subtractStrings(A, B);

    // 결과 출력
    cout  << sum << endl;
    cout  << sub << endl;

    return 0;
}
/*
문제의 정의: 
두 큰 정수 A와 B를 문자열로 입력받고, A + B와 A - B의 값을 문자열로 출력하는 문제입니다. 
입력된 수는 최대 100자리 정수로 주어집니다.

문제의 해결 방안:
1. 문자열로 입력된 두 수를 배열에 저장합니다.
2. 배열을 역순으로 저장하여 포인터 연산을 통해 각 자릿수에 접근하고 연산을 수행합니다.
3. 더하기 연산을 수행하는 함수 addStrings과 빼기 연산을 수행하는 함수 subtractStrings를 작성합니다.
4. 결과 문자열을 생성하여 출력합니다.
*/