#include<cstdio>
#include<cstring>
#define max_lens 101

int main() {
	char A[max_lens], B[max_lens], res[max_lens];
	scanf_s("%s%s", A, max_lens, B, max_lens);
	int temp;
	//当A,B对应位都有数字时
	unsigned int i = strlen(B), j = strlen(A);
	do{
		//奇数位操作
		temp = ((B[i - 1] - '0') + (A[j - 1] - '0')) % 13;
		switch (temp) {
		case 10:
			res[i - 1] = 'J';
			break;
		case 11:
			res[i - 1] = 'Q';
			break;
		case 12:
			res[i - 1] = 'K';
			break;
		default:
			res[i - 1] = temp + '0';
		}
		if (--i == 0 || --j == 0)  //执行减一操作，并且判断终止条件,此时转为偶数位
			break;
		//偶数位操作
		temp = B[i - 1] - A[j - 1];
		if (temp < 0)
			res[i - 1] = temp + 10 + '0';
		else
			res[i - 1] = temp + '0';
		if (--i == 0 || --j == 0)  //执行减一操作，并且判断终止条件,此时转为奇数位
			break;
	} while (1);
	while (i != 0) {  //若B中还有余下数字，直接赋值到res的对应位置
		res[i - 1] = B[i - 1];
		i--;
	}
	for (; i < strlen(B); i++) {
		printf("%c", res[i]);
	}
	return 0;
}