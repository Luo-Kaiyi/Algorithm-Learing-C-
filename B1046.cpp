#include<stdio.h>

int main() {
	int count;
	int call1, n1, call2, n2;
	int glass1 = 0, glass2 = 0;
	printf("输入总的轮数:\t");
	scanf_s("%d", &count);
	printf("输入各轮:\n");
	for (int i = 0; i < count; i++) {
		scanf_s("%d%d%d%d", &call1, &n1, &call2, &n2);
		if (n1 == call1 + call2 && n1 != n2) 
			glass2++;
		if (n2 == call1 + call2 && n1 != n2)
			glass1++;
	}
	printf("甲乙两人分别喝的杯数：%d  %d", glass1, glass2);
	return 0;
}