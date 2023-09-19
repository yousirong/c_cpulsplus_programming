#include <iostream>
#include <cmath>
using namespace std;

int elec_use_func(int elec_month, int elec_use_sum)  // 전기 사용 요금 계산 해주는 함수
{                   
    int normal_won; // 기본요금int
    int use_won;    // 사용량 요금

    int Total_elec_bill;  //전기요금계
    int VAT;  // 부가가치세
    int Based_fee; // 기반요금
    int TAX;  // 세금 
    int Total_billed_fee; // 청구요금계
    if (elec_month != 0)
    {
        switch (elec_month)  // 전력 수요 성수기 동 하계
        {
        case 2:
        case 7:
        case 8:
        case 11:
        case 12:

            if (elec_use_sum > 0 && elec_use_sum <= 200)
            {
                normal_won = 910;
                use_won = 93.3 * elec_use_sum;
            }
            else if (elec_use_sum > 201 && elec_use_sum <= 400)
            {
                normal_won = 1600;
                use_won = 93.3 * 200 + 187.9 * (200 - elec_use_sum);
            }
            else if (elec_use_sum > 400 && elec_use_sum<=1000)
            {
                normal_won = 7300;
                use_won = 93.3 * 200 + 187.9 * 200 + 280.6 * (400 - elec_use_sum);
            }
            else if (elec_use_sum > 1000)
            { // 하계, 동계 1000kwh 초과
                normal_won = 7300;
                use_won = 93.3 * 200 + 187.9 * 200 + 280.6 * 600 + 709.5 * (elec_use_sum-1000);
            }
            Total_elec_bill = normal_won + floor(use_won); // 전기요금계 = 기본요금 + 사용량요금(원단위 미만 절사)
            // cout << "전기요금계" << Total_elec_bill;
            VAT = round(Total_elec_bill * 0.1); // 부가가치세 = 전기요금계의 10%
            // cout << "부가가치세" << VAT;
            Based_fee = ((Total_elec_bill * 0.037) / 10) * 10; // 기반요금 = 전기요금계의 3.7%
            // cout << "기반요금" << Based_fee;
            TAX = round(VAT) + (Based_fee / 10) * 10; // 세금 = 부가가치세(원단위 미만 반올림) + 기반요금(10원 미만 절사)
            // cout << "세금" << TAX;
            Total_billed_fee = ((Total_elec_bill + TAX) / 10) * 10; // 청구요금계(10원 미만 절사) = 전기요금계 + 세금
            // cout << "청구요금계" << Total_billed_fee;
            return Total_billed_fee;
            break;

        default:   // 성수기 동하계 아닌 경우
            // int normal_won = 0; // 기본요금
            // int use_won = 0;    // 사용량 요금

            if (elec_use_sum > 0 && elec_use_sum <= 200)
            {
                normal_won = 910;
                use_won = 93.3 * elec_use_sum;
            }
            else if (elec_use_sum > 201 && elec_use_sum <= 400)
            {
                normal_won = 1600;
                use_won = 93.3 * 200 + 187.9 * (200 - elec_use_sum);
            }
            else if (elec_use_sum > 400)
            {
                normal_won = 7300;
                use_won = 93.3 * 200 + 187.9 * 200 + 280.6 * (elec_use_sum-400);
            }
            // cout << "기본요금 " << normal_won << "사용량요금" << use_won;
            Total_elec_bill = normal_won + floor(use_won); // 전기요금계 = 기본요금 + 사용량요금(원단위 미만 절사)
            // cout << "전기요금계" << Total_elec_bill;
            VAT = round(Total_elec_bill * 0.1); // 부가가치세 = 전기요금계의 10%
            // cout << "부가가치세" << VAT;
            Based_fee = ((Total_elec_bill * 0.037) / 10) * 10; // 기반요금 = 전기요금계의 3.7%
            // cout << "기반요금" << Based_fee;
            TAX = round(VAT) + (Based_fee / 10) * 10; // 세금 = 부가가치세(원단위 미만 반올림) + 기반요금(10원 미만 절사)
            // cout << "세금" << TAX;
            Total_billed_fee = ((Total_elec_bill + TAX) / 10) * 10; // 청구요금계(10원 미만 절사) = 전기요금계 + 세금
            // cout << "청구요금계" << Total_billed_fee;
            return Total_billed_fee;
            break;
        }
    }
}

// 기본적으로 반올림은 round( 숫자 ), 올림은 ceil( 숫자 ), 내림은 floor( 숫자 )이다
int main()
{
    int elec_month;   // 사용한 월 -> 사용자입력
    int elec_use_sum; // 전력사용량 -> 사용자입력

  
    cin >> elec_month >> elec_use_sum; // 사용한 월 전력량 

    cout << elec_use_func(elec_month, elec_use_sum) << endl;  // 전력 사용 요금 계산 함수에 인자 대입
    return 0;
}
/*
문제의 정의 : 
  이 문제는 switch 함수를 적절하게 사용하여 성수인 동하계인 것과 비성수기로 나누어서 요금 계산하는 문제입니다.
문제의 해결 방안 : 
		성수기와 비성기의 요금 계산 방식이 다르므로 switch함수에 (사용한 월) 인자 값을 받아 동하계인 경우와 아닌경우 나누어서 작성했습니다.
		기본 요금과 사용량 요금은 if 구문을 적절하게 사용하여 전기요금 계산표에 나와있는 내용으로 풀이하였습니다.
		원단위 미만 절사, 10원 미만 절사 같은 부분은  반올림 함수 round()와 내림 함수 floor()를 사용하여 풀이하였습니다.
*/