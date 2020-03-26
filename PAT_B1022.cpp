#include<cstdio>
//计算两个数的和，然后以s进制表示
int main() {
	int num1, num2, s;
	scanf_s("%d%d%d", &num1, &num2, &s);
	int sum = num1 + num2;
	int result[31] = {0};

	int i = 0;
	do {    //将各位记入数组result中
		result[i++] = sum % s;
		sum = sum / s;
	} while (sum != 0);

	for (; i >= 0; i--) {  //逆序输出数组
		printf("%d", result[i]);
	}

	return 0;
}