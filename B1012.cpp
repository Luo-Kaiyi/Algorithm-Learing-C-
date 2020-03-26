#include<cstdio>
#define max_num 100

int main() {
	int array[max_num] = {};
	int N;
	float  A1 = 0.0, A2 = 0.0, A3 = 0.0, A4 = 0.0, A5 = 0.0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", array + i);
	}
	int c2 = 0, c3 = 0, c4 = 0;
	for (int i = 0; i < N; i++) {
		switch (array[i] % 5) {
		case 0:
			if (array[i] % 2 == 0)
				A1 += float(array[i]);
			break;
		case 1:
			if (c2) {
				A2 -= float(array[i]);
				c2--;
			}
			else {
				A2 += float(array[i]);
				c2++;
			}
			break;
		case 2:
			c3++;
			break;
		case 3:
			c4++;
			A4 += float(array[i]);
			break;
		case 4:
			if (array[i] > A5)
				A5 = float(array[i]);
			break;
		}
	}
	A3 = float(c3);
	if(c4) 
		A4 = A4 / float(c4);
	float result[5] = { A1, A2, A3, A4, A5 };
	for (int i = 0; i < 5; i++) {
		if (result[i] == 0.0)
			printf("N ");
		else{
			if (i == 3)
				printf("%.1f ", result[i]);
			else
				printf("%d ", int(result[i]));
		}
			
	}
	return 0;
}