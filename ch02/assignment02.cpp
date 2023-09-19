#include <iostream>
#include <cmath>
using namespace std;

int julian_cal_func(int y, int m, int d)  // �ٸ��� ��� �Լ�
{
	y += 8000;
	if (m < 3)
	{
		y--;
		m += 12;
	}
	long julian = ((y * 365) + (y / 4) - (y / 100) + (y / 400) - 1200820 + (m * 153 + 3) / 5 - 92 + (d - 1)) % 7;
	return julian;  // �ٸ��� �� ����
}

int result_func(int y, int m, int d)  // �߸��Էµɰ�� ���� ���� ��°� ��¥�� ������ ���ϴ� �Լ�
{
	string day_week[7] = { "Monday","Tuesday","Wednesday","Thursday", "Friday","Saturday", "Sunday" };  // �迭������ ���� ����
	if (y < 1583) {  // �⵵ ������ ���
		cout << "Wrong year! Try again!" << endl;
		return -1;
	}
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) { // ������ ��� 
		if (m == 2 && d > 29 && d < 1) { //�����ε� 2���� 29�� �ѱ� �� �� �� Ʋ�� ���
			cout << "Wrong day! Try again!" << endl;
			return -1;
		}
		else if (m==1 || m == 3 || m == 7 ||m == 8 ||m == 10 ||m == 12) { //2�� ���� �ƴ� ������ ��¥�� 31���� �޿��� �� �� �� �ʰ��Ȱ�� 
				if (d < 1 || d>31) {
					cout << "Wrong day! Try again!" << endl;
					return -1;

				}
				
				} else {  // 2�� ���� �ƴ� ������ ��¥�� 30���� �޿��� �� �� �� �ʰ��� ���
				if (d < 1 || d>30) {
					cout << "Wrong day! Try again!" << endl;
					return -1;
			} 
			}
		}
	
	else {                                   // ������ �ƴ� ���
		if (m == 2 && d > 28 && d < 1) {  // ������ �ƴѵ� 28�� �ʰ� �� ���
			cout << "Wrong day! Try again!" << endl;
			return -1;
		}
		else if (m==1 || m == 3 || m == 7 ||m == 8 ||m == 10 ||m == 12) {//2�� ���� �ƴ� ������ ��¥�� 31���� �޿��� �� �� �� �ʰ��Ȱ�� 
				if (d < 1 || d>31) {
					cout << "Wrong day! Try again!" << endl;
					return -1;

				}
				
				} else {
				if (d < 1 || d>30) { // 2�� ���� �ƴ� ������ ��¥�� 30���� �޿��� �� �� �� �ʰ��� ���
					cout << "Wrong day! Try again!" << endl;
					return -1;
			} 
			}
	}

	if (m < 1 || m> 12) { // �� ����
		cout << "Wrong month! Try again!" << endl;
		return -1;
	}
	/*if (d < 1 || d>31) {

		cout << "Wrong day! Try again!" << endl;
		return -1;

	}*/
	int res = julian_cal_func(y, m, d);  // �ٸ��� ��� �Լ����� ���� �޾Ƽ� ������ ���� 
	cout << y << "-" << m << "-" << d << " is " << day_week[res] << endl;  // ���� ���
	return 0;
}



int main()
{
	int user_year, user_month, user_day;  // �⵵ �� �� �Է�
	cin >> user_year >> user_month >> user_day;

	result_func(user_year, user_month, user_day);  // ���� ������ִ� �Լ��� ���� ����


	return 0;
}

/*
������ ���� : 
  �� ������ �ٸ��� ��� ���ִ� �Լ��� ����������°� �Բ� �ش糯¥ ������ �����ִ� �Լ��� ���� Ǯ���ϴ� �����Դϴ�.
������ �ذ� ��� : 
		�ٸ��� �� �����ִ� �Լ� julian_cal_func()�� �ۼ��߰�, result_func() �ٸ��� ���� ���Ϸ� ������ִ� �Լ��� �ۼ��߽��ϴ�.
		���� ����� �迭�� ���� �ȹ��� ������ if �������� �����ϸ� �ڵ����� �ʹ� ������� �迭������ ����ؼ� ������ �����߽��ϴ�.
		
		if�������� �⵵�� ��, �� ������ ���������� ��½�Ű�� ���� �⵵ - �� - �� ������ if������ ����ϵ��� �ۼ��߽��ϴ�. 
		���⼭ �߿��� ���� return -1�� �����ν� ���α׷����� ������ ���ٴ� ������ ȣ���ϰ� return 0�� ���� �ʾҽ��ϴ�(return 0���ϸ� �Լ��� ����Ǳ� ������). 
		
		�޷¿��� ���⵵ ������ 30���� ���� �ְ�, 31���� ���� �����Ƿ� if������ ���� �����ؼ� ������ ����ϵ��� �ۼ��߽��ϴ�. 
		
		
*/