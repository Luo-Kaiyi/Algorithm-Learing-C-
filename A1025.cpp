#include<cstdio>
#include<algorithm>
#define max_num 100
using namespace std;

struct Student {
	char id[14];
	int score;
	int loc_num;
	int loc_rank;
	int tol_rank;
}Examinee[max_num];

bool cmp(Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;  
	else
		return strcmp(a.id, b.id) < 0;	//分数相同，按id从小到大排序
}
int main() {
	int room_num, room[max_num];
	scanf_s("%d", &room_num);		//输入考场数
	int stu_num = 0, r = 1;				//考试数量、排名
	//输入数据
	for (int i = 0; i < room_num; i++) {
		scanf_s("%d", &room[i]);		//输入第i个考场的人数
		for (int j = 0; j < room[i]; j++) {
			scanf_s("%s %d", Examinee[stu_num].id, 14, &Examinee[stu_num].score);
			Examinee[stu_num++].loc_num = i + 1;
		}
		r = 1;
		sort(Examinee+ stu_num - room[i], Examinee + stu_num, cmp);
		for (int j = stu_num - room[i]; j < stu_num; j++) {
			if (j > stu_num - room[i] && Examinee[j].score != Examinee[j - 1].score) {
				r = j + 1 - (stu_num -room[i]);
			}
			Examinee[j].loc_rank = r;
		}
	}
	printf("%d\n", stu_num);
	sort(Examinee, Examinee + stu_num, cmp);
	r = 1;
	for (int i = 0; i < stu_num; i++) {
		if (i > 0 && Examinee[i].score != Examinee[i - 1].score) {
			r = i + 1;
		}
		Examinee[i].tol_rank= r;
	}
	for (int i = 0; i < stu_num; i++) {
		printf("%s %d %d %d\n", Examinee[i].id, Examinee[i].tol_rank, Examinee[i].loc_num, Examinee[i].loc_rank);
	}
	return 0;
}