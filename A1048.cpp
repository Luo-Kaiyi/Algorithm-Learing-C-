#include<cstdio>
#include<algorithm>
int main() {
	int N, sum;
	scanf_s("%d%d", &N, &sum);
	int numbers[100];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", numbers + i);
	}
	//第一种方法：Two Points O(n^2)
	/*std::sort(numbers, numbers + N);
	bool sign = false;
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = N - 1; j > i; j--) {
			if (numbers[i] + numbers[j] < sum)
				break;
			if (numbers[i] + numbers[j] == sum) {
				sign = true;
				break;
			}
		}
		if (sign) {
			printf("%d %d", numbers[i], numbers[j]);
			break;
		}
	}
	if (!sign)
		printf("No Solution");*/ 
	//第二种方法：散列法 O(n)
	int hashtable[1000] = {};
	for (int i = 0; i < N; i++) {
		hashtable[numbers[i]]++;
	}
	for (int i = 0; i < sum; i++) {
		if (hashtable[i] != 0 && hashtable[sum - i] != 0) {
			if (i == sum - i && hashtable[i] <= 1)
				continue;
			printf("%d %d", i, sum - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}