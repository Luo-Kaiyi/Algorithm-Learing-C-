#include<stdio.h>
//���벻����9λ����������-123456709�������Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ling jiu
const char spell[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

void FourOuput(int n) {		//���Ķ�����ʽ���һ����λ��
	if (n / 1000 == 0)			//ǧλ
		printf("ling");
	else
		printf("%s Qian", spell[n / 1000]);
	if (n / 100 % 10 != 0)		//��λ
		printf(" %s Bai", spell[n / 100 % 10]);
	else if (n / 1000 != 0 && (n / 10 % 10 != 0|| n % 10 != 0))
			printf(" ling");
	if (n / 10 % 10 != 0)		//ʮλ
		printf(" %s Shi", spell[n / 10 % 10]);
	else if(n / 100 % 10 != 0 && n % 10 != 0)
		printf(" ling");
	if (n % 10 != 0)			//��λ
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
	if (a) {			//��a����
		printf("%s Yi ", spell[a]);  //��λ
		FourOuput(b);
		printf(" Wan ");
		FourOuput(c);
	}
	else if (b) {		//��b����
		if (b >= 1000)   //���b��һ����λ��������ʹ�ú������
			FourOuput(b);
		else {
			if (b / 100 % 10 != 0)		//��λ
				printf("%s Bai", spell[b / 100 % 10]);
			if (b / 10 % 10 != 0)		//ʮλ
				printf(" %s Shi", spell[b / 10 % 10]);
			else if (b / 100 % 10 != 0 && b % 10 != 0)
				printf(" ling");
			if (b % 10 != 0)			//��λ
				printf(" %s", spell[b % 10]);
		}
		printf(" Wan ");
		FourOuput(c);
	}
	else {
		if (c >= 1000)   //���b��һ����λ��������ʹ�ú������
			FourOuput(c);
		else {
			if (c / 100 % 10 != 0)		//��λ
				printf("%s Bai ", spell[c / 100 % 10]);
			if (c / 10 % 10 != 0)		//ʮλ
				printf("%s Shi ", spell[c / 10 % 10]);
			else if (c / 100 % 10 != 0 && c % 10 != 0)
				printf("ling ");
			if (c % 10 != 0)			//��λ
				printf("%s", spell[c % 10]);
		}
	}
	return 0;
}