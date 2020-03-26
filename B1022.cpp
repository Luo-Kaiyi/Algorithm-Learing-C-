#include<stdio.h>

int main() {
	int  A, B, D;
	scanf_s("%d%d%d", &A, &B, &D);

	int sum = A + B;
	int result[31];
	int i = 0;
	do {
		result[i++] = sum % D;
		sum /= D;
	} while (sum != 0);
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", result[j]);
	}
	return 0;
}