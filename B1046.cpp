#include<stdio.h>

int main() {
	int count;
	int call1, n1, call2, n2;
	int glass1 = 0, glass2 = 0;
	printf("�����ܵ�����:\t");
	scanf_s("%d", &count);
	printf("�������:\n");
	for (int i = 0; i < count; i++) {
		scanf_s("%d%d%d%d", &call1, &n1, &call2, &n2);
		if (n1 == call1 + call2 && n1 != n2) 
			glass2++;
		if (n2 == call1 + call2 && n1 != n2)
			glass1++;
	}
	printf("�������˷ֱ�ȵı�����%d  %d", glass1, glass2);
	return 0;
}