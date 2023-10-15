#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// 빈도와 *의 수를 출력하는 함수
void prt_star_histo(char eng, double fq, int star_cnt) {
	cout << "| " << eng;   //알파벳 출력 부분
	cout << " | " <<right << fixed<< setw(5) << setprecision(2) << fq; // 빈도 출력 부분
	cout << "|"; //빈도와 * 사이의 | 출력
	for (int i = 0; i < star_cnt; i++) {// * 출력
		cout << "*";
	}
	//남은 공간은 공백으로 채우기
	for (int i = star_cnt; i < 40; i++) {
		cout<<" ";
	}
	cout<<" |"<<endl;//마지막 | 부분
}

int main() {
	ifstream fp;
	fp.open("data/hamlet.txt");   // hamlet.txt 파일을 열기

	if (fp.is_open()) {  // 파일 열기
		vector<int> frequency(26, 0); //   알파벳(26개) 빈도를 저장할 벡터 초기화
		int total = 0;

		while (!fp.eof()) {// 파일을 전부 읽을 때까지 반복
			char c = char(fp.get()); //  한 글자씩 읽기
			if (isalpha(c)) { //알파벳인 경우에만 처리
				c = tolower(c); //   소문자로 변환
				frequency[c - 'a']++;// 해당 알파벳의 빈도 증가
				total++;     //freq 계산을 위한 알파벳의 등장 개수 
			}
		}


		fp.close(); // 파일 닫기

		cout<<"+----------------------------------------------------+"<<endl;
		cout<<"| C | freq | histogram                               |"<<endl;
		cout<<"+----------------------------------------------------+"<<endl;


		for (int i = 0; i < 26; i++) {

			double freq = static_cast<double>(frequency[i]) / total * 100.0;// 빈도
			int star_cnt = static_cast<int>(freq / 0.5); // * 개수

			char eng = 'a' + i; // 알파벳
			if (freq > 0) {// 빈도가 0이상일경우
				prt_star_histo(eng, freq, star_cnt); //알파벳 빈도 구하는 함수 
			}
		}
		return 0;
	} else {
		cerr<<"Unable to open file"<<endl;
		return -1;
	}
}

/*
문제의 정의 : 
예시 코드에 기반하여 햄릿에서 알파벳 빈도를 구하고, 빈도에 따른 histogram을 출력,
각 문자의 출현 빈도를 계산하고 이에 따라 히스토그램을 출력함으로써 문제를 해결
문제의 해결 방안 : 
prt_star_histo 함수: 
이 함수는 알파벳, 빈도, 그리고 * 개수를 매개변수로 받아서 해당 정보를 출력합니다. setw와 setprecision 함수를 사용하여 출력 형식을 지정하였으며, 오른쪽 정렬로 설정되어 있습니다.

파일 열기 닫기: 주어진 파일인 "data/hamlet.txt" 파일을 열기 위해 ifstream 객체인 fp를 생성하고 해당 파일을 엽니다. 모든 문자 처리가 완료되면 파일을 닫습니다.
벡터 초기화: 알파벳의 빈도를 저장하기 위한 벡터인 frequency 벡터를 선언하고 26개의 요소(알파벳 개수)로 초기화합니다.
문자 읽기 및 빈도 계산: 파일에서 문자 하나씩 읽으면서 알파벳인 경우에만 처리합니다. 읽은 문자가 알파벳이라면 소문자로 변환한 후 해당하는 인덱스 위치의 카운트 값을 증가시킵니다. 이 과정에서 전체 등장한 알파벳 개수(total)도 계산됩니다.

히스토그램 출력: 각각의 알파벳에 대해 빈도와 * 개수를 계산하여 히스토그램 형태로 출력합니다. 이때, 0보다 큰 빈도만 고려하여 출력합니다.

결과 출력: 히스토그램 형태로 결과가 출력됩니다. 상단과 하단에는 구분선이 그려지며, 각 줄마다 C(알파벳), freq(빈도), histogram(* 개수) 정보가 포함된 형식으로 출력됩니다.
이렇게 작성된 코드는 주어진 "data/hamlet.txt" 파일에서 각 알파벳의 출현 빈도와 그에 따른 histogram을 정확히 계산하여 보여줍니다.
*/


