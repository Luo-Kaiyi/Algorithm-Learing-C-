#include<cstdio>
int main() {
	int N;
	scanf_s("%d", &N);
	int bets[1000] = {}, order[100] = {};

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &order[i]);
		bets[order[i]]++;
	}
	bool input = false;
	for (int i = 0; i < N; i++) {
		if (bets[order[i]] == 1) {
			printf("%d", order[i]);
			input = true;
			break;
		}
	}
	if (!input) {
		printf("None");
	}
	return 0;
}