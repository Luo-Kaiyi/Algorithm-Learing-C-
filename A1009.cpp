#include<cstdio>
#define max_size 100
//����������ʽ�ĳ˻�
int main() {
	double fx[max_size] = { 0.0 }, gx[max_size] = { 0.0 }, product[2 * max_size + 1] = { 0.0 };
	int num;		//����ʽ������
	int expo;		//ָ��
	double coef;	//ϵ��

	//�����һ������ʽ
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%lf", &expo, &coef);
		fx[expo] = coef;
	}
	//����ڶ�������ʽ
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%lf", &expo, &coef);
		gx[expo] = coef;
	}
	//�������ʽ�˻�
	for (int i = 0; i < max_size; i++) {
		if (fx[i] != 0.0)
			for (int j = 0; j < max_size; j++) {
				if (gx[j] != 0.0)
					product[i + j] += fx[i] * gx[j];	
			}
	}
	int count = 0;  //ͳ�Ƴ˻��з��������
	for (int i = 0; i < 2 * max_size + 1; i++) {
		if (product[i] != 0.0)
			count++;
	}
	printf("%d", count);
	for (int i = 2 * max_size; i >= 0; i--) {
		if (product[i] != 0.0)
			printf(" %d %.1lf", i, product[i]);
	}
	return 0;
}