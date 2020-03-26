#include<cstdio>
#include<algorithm>
using namespace std;

struct Station {	//����վ��Ϣ
	double price;
	double distance;
};


bool cmp(Station a, Station b) {
	if (a.distance != b.distance)
		return a.distance < b.distance;
	else
		return a.price < b.price;
}

int main() {
	int  N;					//����վ����
	double Cmax, D, Davg;	//������������·�̡���λ����ʻ���롣������ʻ����:Cmax*Davg
	scanf_s("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
	//�������վ��Ϣ
	Station S[500];
	for (int i = 0; i < N; i++) {
		scanf_s("%lf%lf", &S[i].price, &S[i].distance);
	}
	S[N].distance = D;		//���յ�Ҳ��Ϊһ������վ����
	S[N].price = 0;
	sort(S, S + N + 1, cmp);	//���򣺰�������С����

	if (S[0].distance == 0) {
		int now = 0;			//��ǰ����ļ���վ���
		double total = 0.0;		//�ܷ���
		double now_gas = 0.0;	//ʣ������
		while (now < N) {
			int  low_id = -1;
			double lowest = 10000.0;
			for (int i = now + 1; i <= N && S[i].distance - S[now].distance <= Cmax * Davg; i++) {	//��ǰ�ɵ���ļ���վ		
				if (lowest > S[i].price) {
					lowest = S[i].price;
					low_id = i;
					if (S[low_id].price < S[now].price) {		//����ܵ����ͼ۸�ļ���վ��ֹ��ǰѭ��					
						break;
					}
				}
			}
			if (low_id == -1) {			//�޷�������һ������վ,��ֹѭ��
				break;
			}
			else {
				if (S[low_id].price >= S[now].price) {		//����ǰ�۸���ܵ���ļ���վ�ͣ�������
					total += S[now].price * (Cmax - now_gas);
					now_gas = Cmax - (S[low_id].distance - S[now].distance) / Davg;
					now = low_id;
				}
				else {		//����ܵ����ͼ۸�ļ���վ
					if (now_gas < (S[low_id].distance - S[now].distance) / Davg) {  //�����ǰ����С����������
						total += S[now].price * ((S[low_id].distance - S[now].distance) / Davg - now_gas);
						now_gas = 0;
						now = low_id;
					}
					else
						now_gas -= (S[low_id].distance - S[now].distance) / Davg;
				}
			}
		}
		if (now == N) {
			printf("%.2lf", total);
		}
		else
			printf("The maximum distance = %.2lf", S[now].distance + Cmax * Davg);
	}
	else {
		printf("The maximum distance = 0.00");
	}
	return 0;
}