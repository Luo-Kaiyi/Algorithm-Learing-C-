#include<cstdio>

int upper_bound(int a[], int x, int i, int N) {
	int l = i, r = N;
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (a[mid] - a[i - 1] > x)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	int N, S;
	scanf_s("%d%d", &N, &S);
	int sum[100], t;
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &t);
		sum[i] = sum[i - 1] + t;
	}
	bool input = false;
	int epoch = 0;
	while (!input && epoch <= S) {
		for (int i = 1; i <= N; i++) {
			int right = upper_bound(sum, S, i, N);
			if (sum[right - 1] - sum[i - 1] == S) {
				printf("%d-%d\n", i, right - 1);
				input = true;
			}
			else if (sum[right] - sum[i - 1] == S + epoch) {
				printf("%d-%d\n", i, right);
				input = true;
			}
		}
		epoch++;
	}
	return 0;
}