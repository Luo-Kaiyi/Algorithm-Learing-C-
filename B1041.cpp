#include<stdio.h>
#define max_size 100
//根据考生试机号，查询准考证号和考试座位号
typedef struct {
	long long id;
	int TestSeat;
	int ExamSeat;
}Examinee;

int main() {
	int N, M;	//考生人数
	Examinee e[max_size];
	scanf_s("%d", &N);
	//输入考生数据：准考证号、试机号、座位号
	for (int i = 0; i < N; i++) {
		scanf_s("%lld%d%d", &e[i].id, &e[i].TestSeat, &e[i].ExamSeat);
	}
	//输入查询
	scanf_s("%d", &M);
	int query[max_size] = {};
	for (int i = 0; i < M; i++) {
		scanf_s("%d", query + i);
	}
	//输出查询数据
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (query[i] == e[j].TestSeat)
				printf("%lld %d\n", e[j].id, e[j].ExamSeat);
		}	
	}

	return 0;
}