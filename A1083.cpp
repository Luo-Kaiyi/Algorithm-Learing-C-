#include<cstring>
#include<cstdio>
#include<algorithm>

struct Student {
	char name[5];
	char id[11];
	int score;
};

bool cmp(Student a, Student b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return strcmp(a.name, b.name) < 0;
}

int main() {
	int N;
	scanf_s("%d", &N);

	Student stu[10];
	for (int i = 0; i < N; i++) {
		scanf_s("%s %s %d", stu[i].name, 5, stu[i].id, 11, &stu[i].score);
	}
	int low, high;
	scanf_s("%d%d", &low, &high);
	std::sort(stu, stu + N, cmp);
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (stu[i].score >= low && stu[i].score <= high) {
			flag = true;
			printf("%s %s\n", stu[i].name, stu[i].id);
		}
	}
	if (!flag) {
		printf("NONE");
	}
	return 0;
}