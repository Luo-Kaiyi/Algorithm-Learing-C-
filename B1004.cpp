#include<cstdio>

struct Student{
	char name[11];
	char id[11];
	int score;
};

int main() {
	int N;
	scanf_s("%d", &N);
	Student max, min, temp;
	max.score = 0;
	min.score = 100;
	for (int i = 0; i < N; i++) {
		scanf_s("%s%s%d", &temp.name, 11, &temp.id, 11, &temp.score);
		if (max.score < temp.score)
			max = temp;
		if (min.score > temp.score)
			min = temp;
	}
	printf("\n%s %s", max.name, max.id);
	printf("\n%s %s", min.name, min.id);
	return 0;
}