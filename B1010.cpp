#include<cstdio>
#define max_size 100

int main() {
	int fx[max_size] = { 0 }, gx[max_size] = { 0 }, record[max_size] = { 0 };
	printf("以系数-指数形式输入多项式：\n");
	int n, i;	//n为系数，i为对应项的指数
	int j = 0;
	while (scanf_s("%d%d", &n, &i) != EOF) {
		fx[i] = n;
		if (i) {
			gx[i - 1] = fx[i] * i;
			record[j++] = i - 1;		//记录求导后的指数
		}
	}
	if (j == 0)
		printf("0 0");
	for (i = 0; i < j; i++) {
		if (i)
			printf(" ");
		printf("%d %d", gx[record[i]], record[i]);
	}

	return 0;
}