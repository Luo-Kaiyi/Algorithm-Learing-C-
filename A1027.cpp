#include<cstdio>

void Radix13(long long n) {
	int Array[31];
	int num = 0;
	do {
		Array[num++] = n % 13;
		n /= 13;
	} while (n != 0);

	for (int i = num - 1; i >= 0; i--) {
		switch (Array[i]){
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		default:
			printf("%d", Array[i]);
		}
	}
}

int main() {
	long long a, b, c;
	scanf_s("%lld%lld%lld", &a, &b, &c);
	printf("#");
	Radix13(a);
	Radix13(b);
	Radix13(c);
	return 0;
}