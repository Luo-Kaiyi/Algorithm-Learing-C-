#include<cstdio>

struct Student {
	char name[10];
	char sex;
	char id[20];
	int score;
}temp, lowest, highest;

int main() {
	int N;
	scanf_s("%d", &N);
	lowest.score = 101;
	highest.score = -1;
	for (int i = 0; i < N; i++) {
		scanf_s("%s %c %s %d", temp.name, 10, &temp.sex, 1, temp.id, 20, &temp.score);
		if (temp.score > highest.score && temp.sex == 'F')
			highest = temp;
		if (temp.score < lowest.score && temp.sex == 'M')
			lowest = temp;
	}
	if (highest.score == -1)
		printf("Absent\n");
	else
		printf("%s %s\n", highest.name, highest.id);
	if(lowest.score == 101)
		printf("Absent\n");
	else
		printf("%s %s\n", lowest.name, lowest.id);

	if (highest.score == -1 || lowest.score == 101)
		printf("NA");
	else
		printf("%d", highest.score - lowest.score);
	return 0;
}