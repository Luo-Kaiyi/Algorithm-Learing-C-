#include<cstdio>
#include<math.h>
//输入科学计数法表示的数，输出普通数字
#define max_lens 10000
int main() {
	char test[max_lens];
	scanf_s("%s", test, max_lens);

	if (test[0] == '-')
		printf("-");

	//获取数字部分
	double num = double(test[1] - '0');
	int i = 3;
	for (; test[i] != 'E'; i++) {
		num += double(test[i] - '0') / (pow(10.0, double(i) - 2.0));
	}
	//获取指数部分
	i++;
	int  exponent = 0;
	for (int j = i + 1; test[j] >= '0' && test[j] <= '9'; j++) {
		exponent = exponent * 10 +( test[j] - '0');
	}
	//输出。分别采用不同方法（这两种方法都能用）：1.指数为正，计算数字，输出数字   2.指数为负，按字符输出
	if (test[i] == '+') {
		if(exponent>=i-3)
			printf("%lld", long long(num * pow(10.0, exponent)));
		else
			printf("%lf", num * pow(10.0, exponent));
	}
	else 
	{
		printf("0.");
		for (int j = 0; j < exponent - 1; j++) {
			printf("0");
		}
		printf("%c", test[1]);
		for (int j = 3; j < i; j++) {
			printf("%c", test[j]);
		}
	}

	return 0;
}