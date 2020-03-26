#include<stdio.h>
#include<string.h>

int main() {
	int N;
	int score[20];
	int hashTable[100] = {};
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", score + i);
		hashTable[score[i]]++;
	}
	int K;
	int query[20];
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf_s("%d", query + i);
	}
	for (int i = 0; i < K; i++) {
		if (i)
			printf(" ");
		printf("%d", hashTable[query[i]]);
	}
	return 0;
}