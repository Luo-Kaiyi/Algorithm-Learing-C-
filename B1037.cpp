#include<cstdio>
//�ڻ�����������Ǯ

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main() {
	int s1, s2, s3;  //�۸�s1 = 17 * s2, s2 = 29 * s3
	int p1, p2, p3;	 //��Ǯ
	scanf_s("%d.%d.%d %d.%d.%d", &s1, &s2, &s3, &p1, &p2, &p3);
	int r1, r2, r3;
	int symbol = 1;		//��������
	if (s1 > p1 || (s1 == p1 && s2 > p2) || (s1 == p1 && s2 == p2 && s3 > p3)) {
		symbol = 0;		//����۸���ڸ��Ľ�����Ϊ��
		swap(s1, p1), swap(s2, p2), swap(s3, p3);
	}
	//����
	r3 = p3 - s3;
	if (r3 < 0) {
		r3 += 29;
		p2--;
	}
	r2 = p2 - s2;
	if (r2 < 0) {
		r2 += 17;
		p1--;
	}
	r1 = p1 - s1;
	if(symbol)
		printf("%d.%d.%d", r1, r2, r3);
	else
		printf("-%d.%d.%d", r1, r2, r3);
	return 0;
}