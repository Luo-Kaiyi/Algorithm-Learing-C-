#include<cstdio>
#include<cstring>
#define max_lens 101

int main() {
	char A[max_lens], B[max_lens], res[max_lens];
	scanf_s("%s%s", A, max_lens, B, max_lens);
	int temp;
	//��A,B��Ӧλ��������ʱ
	unsigned int i = strlen(B), j = strlen(A);
	do{
		//����λ����
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
		if (--i == 0 || --j == 0)  //ִ�м�һ�����������ж���ֹ����,��ʱתΪż��λ
			break;
		//ż��λ����
		temp = B[i - 1] - A[j - 1];
		if (temp < 0)
			res[i - 1] = temp + 10 + '0';
		else
			res[i - 1] = temp + '0';
		if (--i == 0 || --j == 0)  //ִ�м�һ�����������ж���ֹ����,��ʱתΪ����λ
			break;
	} while (1);
	while (i != 0) {  //��B�л����������֣�ֱ�Ӹ�ֵ��res�Ķ�Ӧλ��
		res[i - 1] = B[i - 1];
		i--;
	}
	for (; i < strlen(B); i++) {
		printf("%c", res[i]);
	}
	return 0;
}