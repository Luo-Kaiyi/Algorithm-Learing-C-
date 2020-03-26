#include<cstdio>

char signal[3] = { 'W','T','L' };

int main() {
	double bet[3];
	double max = 0.0,result = 1.0;
	char s[3];
	int round = 0;
	while (scanf_s("%lf%lf%lf", bet, bet + 1, bet + 2) != EOF) {
		for (int i = 0; i < 3; i++) {
			if (bet[i] > max) {
				max = bet[i];
				s[round] = signal[i];
			}
		}
		round++;
		result *= max;
	}
	for (int i = 0; i < round; i++) {
		printf("%c ", s[i]);
	}
	printf("%.2lf", (result * 0.65 - 1) * 2);
	return 0;
}