#include<stdio.h>
//���磺��-1009876 ���Ϊ��-1,009,876

int main() {
	int a, b, sum;   //���벻����10^9����
	scanf_s("%d%d", &a, &b);
	sum = a + b;
	int res[5], i = 0;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	do {
		res[i++] = sum % 1000;
		sum = sum / 1000;
	} while (sum != 0);
	for (int j = i - 1; j >= 0; j--) {
		if (j == i - 1)
			printf("%d", res[j]);
		else
			printf("%03d", res[j]);
		if (j)
			printf(",");
	}
	return 0;
}