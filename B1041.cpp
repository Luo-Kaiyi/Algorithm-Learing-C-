#include<stdio.h>
#define max_size 100
//���ݿ����Ի��ţ���ѯ׼��֤�źͿ�����λ��
typedef struct {
	long long id;
	int TestSeat;
	int ExamSeat;
}Examinee;

int main() {
	int N, M;	//��������
	Examinee e[max_size];
	scanf_s("%d", &N);
	//���뿼�����ݣ�׼��֤�š��Ի��š���λ��
	for (int i = 0; i < N; i++) {
		scanf_s("%lld%d%d", &e[i].id, &e[i].TestSeat, &e[i].ExamSeat);
	}
	//�����ѯ
	scanf_s("%d", &M);
	int query[max_size] = {};
	for (int i = 0; i < M; i++) {
		scanf_s("%d", query + i);
	}
	//�����ѯ����
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (query[i] == e[j].TestSeat)
				printf("%lld %d\n", e[j].id, e[j].ExamSeat);
		}	
	}

	return 0;
}