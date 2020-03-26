#include<cstdio>
#include<algorithm>
#include<cstring>
#define max_size 20
using namespace std;

struct Examinee {
	int id;
	int total_score;
	int score[5];
	int perfect_solve;
};

bool cmp(Examinee a, Examinee b) {
	if (a.total_score != b.total_score)
		return a.total_score > b.total_score;
	else if (a.perfect_solve != b.perfect_solve)
		return a.perfect_solve > b.perfect_solve;
	else
		return a.id < b.id;
}

int main() {
	int N, K, M;			//人数、题数、提交次数
	scanf_s("%d%d%d", &N, &K, &M);
	int full_mark[5];		//各题的满分
	for (int i = 0; i < K; i++) {
		scanf_s("%d", full_mark + i);
	}
	Examinee data[max_size];
	for (int i = 0; i < N; i++) {  //初始化考生数据
		data[i].id = 0;
		data[i].total_score = 0;
		data[i].perfect_solve = 0;
		data[i].score[0] = -1;
		data[i].score[1] = -1;
		data[i].score[2] = -1;
		data[i].score[3] = -1;
		data[i].score[4] = -1;
	}
	int num = 0;
	for (int i = 0; i < M; i++) {
		int exam_id, ques, sco;
		scanf_s("%d%d%d", &exam_id, &ques, &sco);
		int exist = 0;
		for (int j = 0; j < num; j++) {
			if (data[j].id == exam_id) {
				exist = 1;
				if (data[j].score[ques - 1] < sco) {
					data[j].score[ques - 1] = sco;
				}
			}
		}
		if (!exist) {
			data[num].id = exam_id;
			if (sco != -1)
				data[num++].score[ques - 1] = sco;
			else
				data[num++].score[ques - 1] = 0;
		}
	}
	for (int i = 0; i < num; i++) {			//统计每个人的总分和满分数
		for (int j = 0; j < K; j++) {
			if (data[i].score[j] != -1) {
				data[i].total_score += data[i].score[j];
				if (data[i].score[j] == full_mark[j])
					data[i].perfect_solve++;
			}
		}
	}
	sort(data, data + num, cmp);
	int r = 1;
	for (int i = 0; i < num; i++) {
		if (i > 0 && data[i].total_score != data[i - 1].total_score) {
			r = i + 1;
		}
		printf("%d %05d %d", r, data[i].id, data[i].total_score);
		for (int j = 0; j < K; j++) {
			if (data[i].total_score) {
				if (data[i].score[j] != -1)
					printf(" %d", data[i].score[j]);
				else
					printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}