#include<stdio.h>
const int max_size = 100;

int main() {
	int N = 0, n1, n2;  //N:�ַ�������n1���������е��ַ�����n2�������ַ���
	char words[max_size];
	scanf_s("%s", words, max_size + 1);
	while (words[(N++)+1] != '\0') {}	//ͳ��words�е��ַ�����

	n2 = N + 2, n1 = 0; //��ʼ��n1, n2, N + 2 = 2 * n1 + n2
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