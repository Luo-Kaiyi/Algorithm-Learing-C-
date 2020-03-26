#include<cstdio>

int main() {
	int a1, a2, a3, b1, b2, b3;
	scanf_s("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	int sum;
	sum = a1 * 17 * 29 + a2 * 29 + a3 + b1 * 17 * 29 + b2 * 29 + b3;
	int s1, s2, s3;
	s3 = sum % 29;
	s2 = sum / 29 % 17;
	s1 = sum / 29 / 17;
	printf("%d.%d.%d", s1, s2, s3);
	return 0;
}