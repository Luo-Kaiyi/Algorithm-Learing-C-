#include<stdio.h>
#include<string.h>
#define max_size 20

const int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };		//前17位的权重

bool CheckCodeTest(int n,char M) {   //检查校验码是否正确
	if (M >= '2' && M <= '9') {
		if ((M - '0') + n == 12)
			return true;
	}
	else {
		if ((M == '1' && n == 0) || (M == '0' && n == 1) || (M == 'X' && n == 2))
			return true;
	}
	return false;
}

bool isQualified(char a[]) {	//检验当前身份证件是否合格
	for (unsigned int i = 0; i < strlen(a); i++) {
		if (a[i] < '0' || a[i]>'9')
			return false;
	}
	int Z = 0;
	for (unsigned int i = 0; i < strlen(a) - 1; i++) {
		Z += (a[i] - '0') * weight[i];	//a[i] - '0'将字符型的数字转化为整数数字，再乘上对应位置权重
	}
	return CheckCodeTest(Z % 11, a[17]);  //将所得总权重的模11，与字符数组末尾的校验码对比
}

int main() {
	int N;
	scanf_s("%d", &N);
	int  e_n = 0;
	char input[max_size][max_size];
	//输入数据
	for (int i = 0; i < N; i++) {
		scanf_s("%s", input[i], 20);
	}
	//检验
	for (int i = 0; i < N; i++) {
		if (i)
			printf("\n");
		if (!isQualified(input[i])) {
			for (unsigned int j = 0; j < strlen(input[i]); j++)
				printf("%c", input[i][j]);
			e_n++;
		}
	}
	if (!e_n)	//如果全部合格，输出：All passed
		printf("All passed");
	return 0;
}