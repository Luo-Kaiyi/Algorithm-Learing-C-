#include<cstdio>
//�����������ĺͣ�Ȼ����s���Ʊ�ʾ
int main() {
	int num1, num2, s;
	scanf_s("%d%d%d", &num1, &num2, &s);
	int sum = num1 + num2;
	int result[31] = {0};

	int i = 0;
	do {    //����λ��������result��
		result[i++] = sum % s;
		sum = sum / s;
	} while (sum != 0);

	for (; i >= 0; i--) {  //�����������
		printf("%d", result[i]);
	}

	return 0;
}