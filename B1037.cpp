#include<cstdio>
//在霍格沃兹找零钱

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main() {
	int s1, s2, s3;  //价格s1 = 17 * s2, s2 = 29 * s3
	int p1, p2, p3;	 //付钱
	scanf_s("%d.%d.%d %d.%d.%d", &s1, &s2, &s3, &p1, &p2, &p3);
	int r1, r2, r3;
	int symbol = 1;		//正负符号
	if (s1 > p1 || (s1 == p1 && s2 > p2) || (s1 == p1 && s2 == p2 && s3 > p3)) {
		symbol = 0;		//如果价格大于付的金额，符号为负
		swap(s1, p1), swap(s2, p2), swap(s3, p3);
	}
	//找零
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