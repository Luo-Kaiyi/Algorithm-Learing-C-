#include<cstdio>

int main() {
	int row, col;
	char symbol;
	printf("输入列数和要使用的字符: ");
	scanf_s("%d%c", &col, &symbol, 10);
	if (col % 2 == 0)
		row = col / 2;
	else
		row = (col + 1) / 2;
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (i > 0 && i < row - 1 && j > 0 && j < col - 1)
				printf(" ");
			else 
				printf("%c", symbol);
		}
		printf("\n");
	}
	return 0;
}