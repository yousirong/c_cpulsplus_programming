#include <iostream>
#include <cmath>
using namespace std;

int elec_use_func(int elec_month, int elec_use_sum)  // ���� ��� ��� ��� ���ִ� �Լ�
{                   
    int normal_won; // �⺻���int
    int use_won;    // ��뷮 ���

    int Total_elec_bill;  //�����ݰ�
    int VAT;  // �ΰ���ġ��
    int Based_fee; // ��ݿ��
    int TAX;  // ���� 
    int Total_billed_fee; // û����ݰ�
    if (elec_month != 0)
    {
        switch (elec_month)  // ���� ���� ������ �� �ϰ�
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
            { // �ϰ�, ���� 1000kwh �ʰ�
                normal_won = 7300;
                use_won = 93.3 * 200 + 187.9 * 200 + 280.6 * 600 + 709.5 * (elec_use_sum-1000);
            }
            Total_elec_bill = normal_won + floor(use_won); // �����ݰ� = �⺻��� + ��뷮���(������ �̸� ����)
            // cout << "�����ݰ�" << Total_elec_bill;
            VAT = round(Total_elec_bill * 0.1); // �ΰ���ġ�� = �����ݰ��� 10%
            // cout << "�ΰ���ġ��" << VAT;
            Based_fee = ((Total_elec_bill * 0.037) / 10) * 10; // ��ݿ�� = �����ݰ��� 3.7%
            // cout << "��ݿ��" << Based_fee;
            TAX = round(VAT) + (Based_fee / 10) * 10; // ���� = �ΰ���ġ��(������ �̸� �ݿø�) + ��ݿ��(10�� �̸� ����)
            // cout << "����" << TAX;
            Total_billed_fee = ((Total_elec_bill + TAX) / 10) * 10; // û����ݰ�(10�� �̸� ����) = �����ݰ� + ����
            // cout << "û����ݰ�" << Total_billed_fee;
            return Total_billed_fee;
            break;

        default:   // ������ ���ϰ� �ƴ� ���
            // int normal_won = 0; // �⺻���
            // int use_won = 0;    // ��뷮 ���

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
            // cout << "�⺻��� " << normal_won << "��뷮���" << use_won;
            Total_elec_bill = normal_won + floor(use_won); // �����ݰ� = �⺻��� + ��뷮���(������ �̸� ����)
            // cout << "�����ݰ�" << Total_elec_bill;
            VAT = round(Total_elec_bill * 0.1); // �ΰ���ġ�� = �����ݰ��� 10%
            // cout << "�ΰ���ġ��" << VAT;
            Based_fee = ((Total_elec_bill * 0.037) / 10) * 10; // ��ݿ�� = �����ݰ��� 3.7%
            // cout << "��ݿ��" << Based_fee;
            TAX = round(VAT) + (Based_fee / 10) * 10; // ���� = �ΰ���ġ��(������ �̸� �ݿø�) + ��ݿ��(10�� �̸� ����)
            // cout << "����" << TAX;
            Total_billed_fee = ((Total_elec_bill + TAX) / 10) * 10; // û����ݰ�(10�� �̸� ����) = �����ݰ� + ����
            // cout << "û����ݰ�" << Total_billed_fee;
            return Total_billed_fee;
            break;
        }
    }
}

// �⺻������ �ݿø��� round( ���� ), �ø��� ceil( ���� ), ������ floor( ���� )�̴�
int main()
{
    int elec_month;   // ����� �� -> ������Է�
    int elec_use_sum; // ���»�뷮 -> ������Է�

  
    cin >> elec_month >> elec_use_sum; // ����� �� ���·� 

    cout << elec_use_func(elec_month, elec_use_sum) << endl;  // ���� ��� ��� ��� �Լ��� ���� ����
    return 0;
}
/*
������ ���� : 
  �� ������ switch �Լ��� �����ϰ� ����Ͽ� ������ ���ϰ��� �Ͱ� �񼺼���� ����� ��� ����ϴ� �����Դϴ�.
������ �ذ� ��� : 
		������� �񼺱��� ��� ��� ����� �ٸ��Ƿ� switch�Լ��� (����� ��) ���� ���� �޾� ���ϰ��� ���� �ƴѰ�� ����� �ۼ��߽��ϴ�.
		�⺻ ��ݰ� ��뷮 ����� if ������ �����ϰ� ����Ͽ� ������ ���ǥ�� �����ִ� �������� Ǯ���Ͽ����ϴ�.
		������ �̸� ����, 10�� �̸� ���� ���� �κ���  �ݿø� �Լ� round()�� ���� �Լ� floor()�� ����Ͽ� Ǯ���Ͽ����ϴ�.
*/