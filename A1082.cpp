#include<stdio.h>
//输入不超过9位的数：例如-123456709，输出：Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ling jiu
const char spell[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

void FourOuput(int n) {		//中文读音方式输出一个四位数
	if (n / 1000 == 0)			//千位
		printf("ling");
	else
		printf("%s Qian", spell[n / 1000]);
	if (n / 100 % 10 != 0)		//百位
		printf(" %s Bai", spell[n / 100 % 10]);
	else if (n / 1000 != 0 && (n / 10 % 10 != 0|| n % 10 != 0))
			printf(" ling");
	if (n / 10 % 10 != 0)		//十位
		printf(" %s Shi", spell[n / 10 % 10]);
	else if(n / 100 % 10 != 0 && n % 10 != 0)
		printf(" ling");
	if (n % 10 != 0)			//个位
		printf(" %s", spell[n % 10]);
}

int main() {
	int num;
	scanf_s("%d", &num);
	if (num < 0) {
		printf("Fu ");
		num = -num;
	}
	int a, b, c;
	a = num / 100000000;
	b = num / 10000 % 10000;
	c = num % 10000;
	if (a) {			//若a非零
		printf("%s Yi ", spell[a]);  //亿位
		FourOuput(b);
		printf(" Wan ");
		FourOuput(c);
	}
	else if (b) {		//若b非零
		if (b >= 1000)   //如果b是一个四位数，可以使用函数输出
			FourOuput(b);
		else {
			if (b / 100 % 10 != 0)		//百位
				printf("%s Bai", spell[b / 100 % 10]);
			if (b / 10 % 10 != 0)		//十位
				printf(" %s Shi", spell[b / 10 % 10]);
			else if (b / 100 % 10 != 0 && b % 10 != 0)
				printf(" ling");
			if (b % 10 != 0)			//个位
				printf(" %s", spell[b % 10]);
		}
		printf(" Wan ");
		FourOuput(c);
	}
	else {
		if (c >= 1000)   //如果b是一个四位数，可以使用函数输出
			FourOuput(c);
		else {
			if (c / 100 % 10 != 0)		//百位
				printf("%s Bai ", spell[c / 100 % 10]);
			if (c / 10 % 10 != 0)		//十位
				printf("%s Shi ", spell[c / 10 % 10]);
			else if (c / 100 % 10 != 0 && c % 10 != 0)
				printf("ling ");
			if (c % 10 != 0)			//个位
				printf("%s", spell[c % 10]);
		}
	}
	return 0;
}