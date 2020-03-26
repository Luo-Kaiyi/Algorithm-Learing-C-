#include<stdio.h>
#include<string.h>
#define max_size 20

const int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };		//ǰ17λ��Ȩ��

bool CheckCodeTest(int n,char M) {   //���У�����Ƿ���ȷ
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

bool isQualified(char a[]) {	//���鵱ǰ���֤���Ƿ�ϸ�
	for (unsigned int i = 0; i < strlen(a); i++) {
		if (a[i] < '0' || a[i]>'9')
			return false;
	}
	int Z = 0;
	for (unsigned int i = 0; i < strlen(a) - 1; i++) {
		Z += (a[i] - '0') * weight[i];	//a[i] - '0'���ַ��͵�����ת��Ϊ�������֣��ٳ��϶�Ӧλ��Ȩ��
	}
	return CheckCodeTest(Z % 11, a[17]);  //��������Ȩ�ص�ģ11�����ַ�����ĩβ��У����Ա�
}

int main() {
	int N;
	scanf_s("%d", &N);
	int  e_n = 0;
	char input[max_size][max_size];
	//��������
	for (int i = 0; i < N; i++) {
		scanf_s("%s", input[i], 20);
	}
	//����
	for (int i = 0; i < N; i++) {
		if (i)
			printf("\n");
		if (!isQualified(input[i])) {
			for (unsigned int j = 0; j < strlen(input[i]); j++)
				printf("%c", input[i][j]);
			e_n++;
		}
	}
	if (!e_n)	//���ȫ���ϸ������All passed
		printf("All passed");
	return 0;
}