#include<cstdio>
const int max_size = 100;
//�ϲ�����һԪ����ʽ
int main() {
	float result[max_size] = { 0.0 };
	int num;
	int exponent;	//ָ��
	float coef;		//ϵ��
	//�����һ������ʽ
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%f", &exponent, &coef);
		result[exponent] += coef;
	}
	//����ڶ�������ʽ
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%f", &exponent, &coef);
		result[exponent] += coef;
	}
	//�ϲ�����ʽ����¼������ĸ���
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (result[i] != 0.0)
			count++;
	}
	//������
	printf("%d ", count);
	for (int i = 99; i >= 0; i--) {
		if (result[i] != 0.0) {
			printf("%d %.1f", i, result[i]);
			if (--count)
				printf(" ");
		}
	}
	return 0;
}