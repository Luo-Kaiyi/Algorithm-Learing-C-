#include<cstdio>
#define max_size 100

int main() {
	int fx[max_size] = { 0 }, gx[max_size] = { 0 }, record[max_size] = { 0 };
	printf("��ϵ��-ָ����ʽ�������ʽ��\n");
	int n, i;	//nΪϵ����iΪ��Ӧ���ָ��
	int j = 0;
	while (scanf_s("%d%d", &n, &i) != EOF) {
		fx[i] = n;
		if (i) {
			gx[i - 1] = fx[i] * i;
			record[j++] = i - 1;		//��¼�󵼺��ָ��
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