#include<cstdio>
#include<cstring>
#include<algorithm>

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	scanf_s("%d", &N);
	int numbers[100] = {};
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numbers[i]);
	}
	bool hashtable[1000];
	memset(hashtable, false, 1000);
	for (int i = 0; i < N; i++) {
		int m = numbers[i];
		while (m != 1) {
			if (m % 2 == 0)
				m = m / 2;
			else if (m % 2 == 1)
				m = (3 * m + 1) / 2;
			hashtable[m] = true;
		}
	}
	std::sort(numbers, numbers + N, cmp);  //从大到小排序
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (!hashtable[numbers[i]]) {
			if (count)
				printf(" ");
			printf("%d", numbers[i]);
			count++;
		}
	}
	return 0;
}