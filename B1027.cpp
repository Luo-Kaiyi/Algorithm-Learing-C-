#include<stdio.h>

int main() {
	int N;
	char symbol;
	scanf_s("%d %c", &N, &symbol, 1);

	int num = 1, deep = 1;
	int base = 1;   //顶行和底行的字符数
	while (num + 2 * (base + 2) <= N) {
		base += 2;
		num = num + 2 * base;
		deep++; 	
	}
	for (int i = 0; i < deep; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < base - i * 2; j++)
			printf("%c", symbol);
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("\n");
	}
	for (int i = deep - 2; i >= 0; i--) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < base - i * 2; j++)
			printf("%c", symbol);
		for (int j = 0; j < i; j++)
			printf(" ");
		printf("\n");
	}
	printf("%d", N - num);
}