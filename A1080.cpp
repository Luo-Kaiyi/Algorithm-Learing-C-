#include<cstdio>
#include<algorithm>
#define max_size 20
using namespace std;

struct Examinee {
	int id, GE, GI;
	int appl[10];
	int rank;
};

bool cmp(Examinee a, Examinee b) {
	if (a.GE + a.GI != b.GE + b.GI)
		return a.GE + a.GI > b.GE + b.GI;
	else if (a.GE != b.GE)
		return a.GE > b.GE;
	else
		return a.id < b.id;

}

int main() {
	int N, M, K;		//����������ѧУ����ÿ���˿����־Ը��
	scanf_s("%d%d%d", &N, &M, &K);

	int enrolment[10] = { 0 };	//��������
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &enrolment[i]);
	}
	//����ѧ���ɼ���־Ը
	Examinee stu[max_size];
	for (int i = 0; i < N; i++) {
		stu[i].id = i;
		scanf_s("%d%d", &stu[i].GE, &stu[i].GI);
		for (int j = 0; j < K; j++) {
			scanf_s("%d", &stu[i].appl[j]);
		}
	}
	
	sort(stu, stu + N, cmp);	//����
	int r = 1;	
	for (int i = 0; i < N; i++) {
		if (i > 0 && (stu[i].GE + stu[i].GI != stu[i - 1].GE + stu[i - 1].GI || stu[i].GE != stu[i - 1].GE)) {
			r = i + 1;
		}
		stu[i].rank = r;
	}
	int enrol_result[10][5] = { -1 };	//����ѧУ�����ս��
	int enroled[10] = { 0 };		//����ѧУ�ĵ�ǰ��������
	int last_enrol[10] = { -1 };	//����ѧУ��һ�����յ�ѧ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (enroled[stu[i].appl[j]] < enrolment[stu[i].appl[j]] || stu[i].rank == stu[last_enrol[stu[i].appl[j]]].rank) {
				last_enrol[stu[i].appl[j]] = i;
				enrol_result[stu[i].appl[j]][enroled[stu[i].appl[j]]++] = stu[i].id;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if(i)
			printf("\n");
		for (int j = 0; j < enroled[i]; j++) {
			if (j)
				printf(" ");
			printf("%d", enrol_result[i][j]);
		}
	}
	return 0;
}