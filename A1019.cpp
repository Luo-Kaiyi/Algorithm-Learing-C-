#include<cstdio>

int main() {
	int n, d;
	scanf_s("%d%d", &n, &d);
	int ans[100];
	int num = 0;
	do {
		ans[num++] = n % d;
		n /= d;
	} while (n != 0);
	
	bool is = true;
	for (int i = 0; i < (num - 1) / 2; i++) {
		if (ans[i] != ans[num - 1 - i])
			is = false;
	}
	if (is)
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i)
			printf(" ");
	}
	return  0;
}