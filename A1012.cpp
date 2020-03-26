#include<cstdio>
#include<algorithm>
using namespace std;
#define max_size 100

struct Student {
	int id;
	int score[4];
};

char course[4] = { 'A','C','M','E' };
int now;

bool cmp(Student a, Student b) {
	return a.score[now] > b.score[now];
}

int main() {
	int n, m;	//学生数量、查询次数
	scanf_s("%d%d", &n, &m);
	Student data[max_size];
	for (int i = 0; i < n; i++) {	//输入成绩
		scanf_s("%d %d %d %d", &data[i].id, data[i].score + 1, data[i].score + 2, data[i].score + 3);
		data[i].score[0] = (data[i].score[1] + data[i].score[2] + data[i].score[3]) / 3;
	}
	
	//统计排名
	int rank[100][4] = { 0 };
	for (now = 0; now < 4; now++) {
		sort(data, data + n, cmp);
		rank[data[0].id][now] = 1;
		for (int j = 1; j < n; j++) {
			if (data[j].score[now] == data[j - 1].score[now])
				rank[data[j].id][now] = rank[data[j - 1].id][now];
			else
				rank[data[j].id][now] = j + 1;
		}
	}

	int query[max_size];
	for (int i = 0; i < m; i++) {	//输入查询
		scanf_s("%d", query + i);
	}
	for (int i = 0; i < m; i++) {	//输出查询结果
		if (rank[query[i]][0] == 0)
			printf("N/A\n");
		else {
			int k = 0;
			for (int j = 0; j < 4; j++) {
				if (rank[query[i]][j] < rank[query[i]][k])
					k = j;
			}
			printf("%d %c\n", rank[query[i]][k], course[k]); 
		}
	}
	return 0;
}