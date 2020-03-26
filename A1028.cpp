#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define max_size 10

struct Student {
	int id;
	char name[8];
	int score;
};

bool cmp1(Student a, Student b) {
	return a.id < b.id;
}

bool cmp2(Student a, Student b) {
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else
		return a.id < b.id;
}

bool cmp3(Student a, Student b) {
	if(a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}

void Output(Student a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%06d %s %02d\n", a[i].id, a[i].name, a[i].score);
	}
}

int main() {
	int N, C;
	scanf_s("%d%d", &N, &C);

	Student data[max_size];
	for (int i = 0; i < N; i++) {
		scanf_s("%d %s %d", &data[i].id, data[i].name, 8, &data[i].score);
	}
	switch (C) {
	case 1:
		sort(data, data + N, cmp1);
		Output(data, N);
		break;
	case 2:
		sort(data, data + N, cmp2);
		Output(data, N);
		break;
	case 3:
		sort(data, data + N, cmp3);
		Output(data, N);
		break;
	default:
		printf("查询方式无效！\n");
	}
	return 0;
}