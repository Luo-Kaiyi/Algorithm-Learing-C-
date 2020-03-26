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
	int N, M, K;		//考生人数、学校数、每个人可填报的志愿数
	scanf_s("%d%d%d", &N, &M, &K);

	int enrolment[10] = { 0 };	//招收人数
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &enrolment[i]);
	}
	//输入学生成绩和志愿
	Examinee stu[max_size];
	for (int i = 0; i < N; i++) {
		stu[i].id = i;
		scanf_s("%d%d", &stu[i].GE, &stu[i].GI);
		for (int j = 0; j < K; j++) {
			scanf_s("%d", &stu[i].appl[j]);
		}
	}
	
	sort(stu, stu + N, cmp);	//排序
	int r = 1;	
	for (int i = 0; i < N; i++) {
		if (i > 0 && (stu[i].GE + stu[i].GI != stu[i - 1].GE + stu[i - 1].GI || stu[i].GE != stu[i - 1].GE)) {
			r = i + 1;
		}
		stu[i].rank = r;
	}
	int enrol_result[10][5] = { -1 };	//各个学校的招收结果
	int enroled[10] = { 0 };		//各个学校的当前已收人数
	int last_enrol[10] = { -1 };	//各个学校上一个招收的学生
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