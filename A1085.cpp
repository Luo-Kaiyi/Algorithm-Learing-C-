#include<cstdio>
#include<algorithm>
using namespace std;

int BinarySearch(long long a[], int left, int right, long long x) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

int main() {
	long long N, p;
	scanf_s("%lld%lld", &N, &p);
	long long num[100];
	for (int i = 0; i < N; i++) {
		scanf_s("%lld", num + i);
	}
	sort(num, num + N);
	int max = 0;
	for (int i = 0; i < N; i++) {
		long long bound = num[i] * p;
		int r = BinarySearch(num, i, N - 1, bound);	
		if (max < r - i) {
			max = r - i;
		}
	}
	printf("%d", max);
	return 0;
}