#include<cstdio>

int main() {
	long long A, B, C;
	int num;
	long long sum;
	scanf_s("%d", &num);
	for (int step = 0; step < num; step++) {
		scanf_s("%lld%lld%lld", &A, &B, &C);
		sum = A + B;
		if (A > 0 && B > 0 && sum < 0)	      //���������
			printf("Case #%d:true\n", step + 1);
		else if (A < 0 && B < 0 && sum >= 0)  //���������
			printf("Case #%d:false\n", step + 1);
		else {							      //�����						
			if (sum > C)
				printf("Case #%d:true\n", step + 1);
			else
				printf("Case #%d:false\n", step + 1);
		}
	}

	return 0;
}