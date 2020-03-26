#include<stdio.h>
const int max_size = 100;

int main() {
	int N = 0, n1, n2;  //N:字符总数，n1：左右两列的字符数，n2：底行字符数
	char words[max_size];
	scanf_s("%s", words, max_size + 1);
	while (words[(N++)+1] != '\0') {}	//统计words中的字符个数

	n2 = N + 2, n1 = 0; //初始化n1, n2, N + 2 = 2 * n1 + n2
	while (n1 <= n2 - 3) {
		n1++;
		n2 -= 2;
	}

	for (int i = 0; i < n1 - 1; i++) {
		printf("%c", words[i]);
		for (int j = 0; j < n2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", words[N - 1 - i]);
	}
	for (int i = 0; i <  n2; i++) {
		printf("%c", words[n1 + i - 1]);
	}
	return 0;
}