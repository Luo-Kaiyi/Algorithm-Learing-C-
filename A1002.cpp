#include<cstdio>
const int max_size = 100;
//合并两个一元多项式
int main() {
	float result[max_size] = { 0.0 };
	int num;
	int exponent;	//指数
	float coef;		//系数
	//输入第一个多项式
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%f", &exponent, &coef);
		result[exponent] += coef;
	}
	//输入第二个多项式
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%f", &exponent, &coef);
		result[exponent] += coef;
	}
	//合并多项式并记录非零项的个数
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (result[i] != 0.0)
			count++;
	}
	//输出结果
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