#include<cstdio>
#include<algorithm>
using namespace std;

int lower_bound(int a[], int i, int n, int x) {
	int l = i, r = n;
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (a[i] + a[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

//A1048的二分解法
int main() {
	int N, S;
	scanf_s("%d%d", &N, &S);
	int num[100];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", num + i);
	}
	sort(num, num + N);
	int i;
	for (i = 0; i < N; i++) {
		int ri = lower_bound(num, i, N - 1, S);
		if (num[i] + num[ri] == S && i != ri) {
			printf("%d %d", num[i], num[ri]);
			break;
		}
	}
	if (i == N)
		printf("No solution");
	return 0;
}