#include<cstdio>
#include<cstring>
#define max_size 101

const char spell[10][5] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };

void Rec_out(int n) {	//��n�Եݹ鷽ʽ�ӵ�λ����λ�����ƴ����
	if (n) {
		Rec_out(n / 10);
		printf(" %s", spell[n % 10]);	
	}
}

int main() {
	char a[max_size];
	scanf_s("%s", a, 101);
	int sum = 0;
	for (unsigned int i = 0; i < strlen(a); i++) {
		sum += a[i] - '0';
	}
	Rec_out(sum);  
	return 0;
}