#include<cstdio>

int main() {
	unsigned long long num;
	scanf_s("%lld", &num);
	int res[10] = { 0 };
	do {
		res[num % 10]++;
		num /= 10;
	} while (num != 0);

	for (int i = 0; i < 10; i++) {
		if (res[i])
			printf("%d:%d\n", i, res[i]);
	}
	return 0;
}