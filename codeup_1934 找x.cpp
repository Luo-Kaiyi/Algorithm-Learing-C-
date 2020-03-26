#include<cstdio>
#include<cstdlib>

int main() {
	int n, d, i = 0;
	int list[100] = { 0 };
	printf("Enter the number of digits:");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		scanf_s("%d", list + i);
	}
	printf("Enter a digit, an index will be return.");
	scanf_s("%d", &d);

	for (i = 0; i < n; i++) {
		if (list[i] == d) {
		printf("Index = %d", i);
		break;
		}
	}

	if (i == n) {
		printf("Index = -1");
	}
	return 0;
}