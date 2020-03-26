#include<cstdio>
#define max_size 100
//求两个多项式的乘积
int main() {
	double fx[max_size] = { 0.0 }, gx[max_size] = { 0.0 }, product[2 * max_size + 1] = { 0.0 };
	int num;		//多项式的项数
	int expo;		//指数
	double coef;	//系数

	//输入第一个多项式
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%lf", &expo, &coef);
		fx[expo] = coef;
	}
	//输入第二个多项式
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf_s("%d%lf", &expo, &coef);
		gx[expo] = coef;
	}
	//计算多项式乘积
	for (int i = 0; i < max_size; i++) {
		if (fx[i] != 0.0)
			for (int j = 0; j < max_size; j++) {
				if (gx[j] != 0.0)
					product[i + j] += fx[i] * gx[j];	
			}
	}
	int count = 0;  //统计乘积中非零项个数
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