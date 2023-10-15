#include <iostream>
using namespace std;


bool detect_P_num(int x) {  // 소수인지 판별해주는 에라토스테네스 체 bool함수
	if (x<=1) {  // 입력된 정수가 1이하 일 경우 false
		
		return false;
	}
	if (x<=3) {  // 3이 입력될 경우 소수 2,3 개 출력해야됨, 2를 결과값에 포함해야함.
		return true;
	}
	if (x%2==0|| x%3 ==0) { // 2의 배수와 3의 배수 값들은 소수가 아니기 때문에 false를 반환 합니다. 
		
		return false;
	}
	int i=5; //x=5의 배수들을 false로 변경해주는 과정을 반복해주면 소수가 아닌 수들은 false 반환합니다.
	while (i*i<=x) {
		if (x %i==0 ||x% (i+2)== 0) { //마지막으로  i * i가 n이하가 되는 만큼만 반복문을 돌리면 소수를 판별할 수 있습니다. 
			
			return false;
		}
	
		i+=6;  // n까지 수행
	}
	return true;
}

int cal_p_num(int n) {  // 소수의 개수를 판별해주는 함수 입니다.
	int p_sum = 0;   // p_sum변수는 소수의 개수
	// bool prime_detect = true;
	for (int i = 2; i <= n; i++) {  //for 구문 돌려서 2부터 n까지의 소수의 개수를 구하는 것이므로 
		//입력받은 n을 인자로 받아와서 n까지의 소수 판별함
		if (detect_P_num(i)) {
			// cout<<num;
			p_sum++;
				// }else{
					// prime_detect =false;
				// }
	}
	}
	return p_sum;  // 소수 개수 반환 
}

int main() {
	int n;
	cin >> n;
	int res_sum = cal_p_num(n); // 사용자에게 정수 n을 입력받아 소수 개수르 판별하는 함수에 대입
	cout << res_sum<<endl;  // 소수 개수 출력
	return 0;
}
/*
문제의 정의 :
소수의 개수를 구하는 1~n까지 일일히 검사해서 소수 인지 판별하려면 시간복잡도가 너무 커집니다.
여기서 시간복잡도를 획기적으로 줄이기위해 에라토스테네스의 체를 코드화해서 소수의 개수를 구하는 문제입니다. 
문제의 해결 방안 :

일단 에라토스테네스의 체를 구현하기 위해서는 
소수면 true, 소수가 아닌 경우 false를 반환해주는 bool 함수를 구현했습니다. 
2의 배수의 값들은 소수가 아니기 때문에 false를 반환 합니다.

마찬가지로 x=3의 배수들, x=4는 2의 배수로서 소수가 아닌 것으로 판별되었기 때문에 넘어가고,
x=5의 배수들을 false로 변경해주는 과정을 반복해주면 소수가 아닌 수들은 false 반환합니다.

마지막으로  i * i가 n이하가 되는 만큼만 반복문을 돌리면 소수를 판별할 수 있습니다. 
다음과 같이 2~n까지의 소수의 개수를 구합니다.

*/