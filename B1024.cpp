#include<cstdio>
#include<math.h>
//�����ѧ��������ʾ�����������ͨ����
#define max_lens 10000
int main() {
	char test[max_lens];
	scanf_s("%s", test, max_lens);

	if (test[0] == '-')
		printf("-");

	//��ȡ���ֲ���
	double num = double(test[1] - '0');
	int i = 3;
	for (; test[i] != 'E'; i++) {
		num += double(test[i] - '0') / (pow(10.0, double(i) - 2.0));
	}
	//��ȡָ������
	i++;
	int  exponent = 0;
	for (int j = i + 1; test[j] >= '0' && test[j] <= '9'; j++) {
		exponent = exponent * 10 +( test[j] - '0');
	}
	//������ֱ���ò�ͬ�����������ַ��������ã���1.ָ��Ϊ�����������֣��������   2.ָ��Ϊ�������ַ����
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