#include<stdio.h>

int main() {
	int num;
	int h, m, l;
	scanf_s("%d", &num);
	h = num / 100;
	m = num / 10 % 10;
	l = num % 10;
	for (int i = 0; i < h; i++) {
		printf("B");
	}
	for (int i = 0; i < m; i++) {
		printf("S");
	}
	for (int i = 1; i <= l; i++) {
		printf("%d", i);
	}

	return 0;
}