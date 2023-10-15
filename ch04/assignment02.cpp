#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Student {
	public:
	int id;
	int score;
	int absen;
	int Total_sc;
	string grade;

	// 생성자: 학생 정보를 초기화하고 finalScore와 grade를 계산합니다.
	Student(int id, int score, int absen) : id(id), score(score), absen(absen) {
		calculate_sc(); // finalScore를 계산합니다.
		grade = ""; // 초기 등급은 빈 문자열로 초기화합니다.
	}

	private:
	// 최종 점수와 등급을 계산하는 함수
	void calculate_sc() {
		if (absen > 16) {
		 Total_sc = score - 2 * absen; // 결석이 16 이상이면 F 학점
			grade = "F";
		} else {
		 Total_sc = score - 2 * absen; // 결석이 16 이하이면 Total_sc 계산
		}
	}
};

vector<Student> students; // 학생 정보를 저장하는 벡터

// 주어진 finalScore를 기반으로 학생의 등수를 계산하는 함수
int cal_rank(int Total_sc) {
	int cnt_student_sc = 0;

	for (const auto& s : students) {
		if (s.Total_sc > Total_sc)
			cnt_student_sc++;
	}

	return cnt_student_sc + 1; // 등수는 '같거나 높은 점수를 가진 사람 수 + 1'
}

// 학생들의 등급을 계산하는 함수
void Cal_grades() {
	int Total_Stu = students.size(); // 총 학생 수를 얻습니다.

	for (auto& student : students) {
			if (student.absen > 16) {
				student.Total_sc = student.score - 2 * student.absen;
				student.grade = "F";
			} else {
				student.Total_sc = student.score - 2 * student.absen;
			}
		if (student.grade != "F") { // 학생이 이미 F 학점을 받은 경우 등급을 다시 계산하지 않습니다.
			int rank = cal_rank(student.Total_sc); // 학생의 등수를 얻습니다.

			// 등급 계산 규칙에 따라 등급을 설정합니다.
			if (rank <= round(Total_Stu * 0.1))
				student.grade = "A+";
			else if (rank <= floor(Total_Stu * 0.25))
				student.grade = "A0";
			else if (rank <= round(Total_Stu * 0.4))
				student.grade = "B+";
			else if (rank <= floor(Total_Stu * 0.6))
				student.grade = "B0";
			else if (rank <= round(Total_Stu * 0.8))
				student.grade = "C+";
			else if (rank <= floor(Total_Stu * 0.9))
				student.grade = "C0";
			else if (rank <= floor(Total_Stu * 0.95))
				student.grade = "D+";
			else
				student.grade = "D0";
		}
	}
}

// 학생들을 finalScore와 id에 따라 버블 정렬하는 함수
void bubble_sort_sc() {
	int n = students.size();

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (students[j].Total_sc < students[j + 1].Total_sc) {
				swap(students[j], students[j + 1]);
			} else if (students[j].Total_sc == students[j + 1].Total_sc && students[j].id > students[j + 1].id) {
				swap(students[j], students[j + 1]);
			}
		}
	}
}

// 학생들의 정보와 등급을 출력하는 함수
void prt_res() {
	for (const auto& s : students) {
		cout << s.id << ' ' << s.Total_sc << ' ' << s.grade << endl;
	}
}

int main() {
	int n; // 학생 수
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int id, score, absen;
		cin >> id >> score >> absen;

		students.push_back(Student(id, score, absen)); // 학생 정보를 벡터에 추가
	}

	Cal_grades(); // 등급 계산
	bubble_sort_sc(); // 학생들을 정렬
	prt_res(); // 결과 출력

	return 0;
}
/*
문제 정의:
학생들의 학번, 시험 점수, 결석 일수를 입력받아, 주어진 규칙에 따라 각 학생의 최종 점수와 학점을 계산하고 출력하는 프로그램을 작성하는 것입니다. 학점은 상위 백분율에 따라 부여되며, 결석 일수가 16 이상인 학생은 학점 F를 받는 프로그램입니다.

문제의 해결 방안:

1. 클래스 `Student`를 정의하고, 학생의 정보를 저장하며 최종 점수와 학점을 계산하는 생성자를 포함

2. 입력으로 학생의 수 n명을 받고, 각 학생의 학번, 시험 점수, 결석 일수를 입력받아 Student 객체를 생성하고 이를 벡터에 저장

3. Cal_grades 함수를 사용하여 학생들의 등급을 계산합니다. 이 함수는 학생의 등수를 계산하고 주어진 규칙에 따라 학점을 설정합니다.

4. `bubble_sort_sc` 함수를 사용하여 학생들을 최종 점수와 학번에 따라 버블 정렬하여 정렬합니다.

5. `prt_res` 함수를 사용하여 학생들의 정보를 출력합니다.

6. 학점 계산에 필요한 규칙에 따라 등급을 부여합니다. 등급은 학생 수의 백분율에 따라 부여되며, 점수가 같을 경우 학번이 낮은 학생이 우선됩니다.

7. 학생의 최종 점수가 결석일수에 따라 계산되며, 결석일수가 16 이상인 경우 학점이 F로 설정됩니다.

8. 마지막으로, 모든 학생의 정보와 학점이 출력됩니다.

이렇게 작성된 프로그램은 주어진 입력에 따라 학생들의 최종 점수와 학점을 계산하고 정렬하여 출력할 것입니다.
*/