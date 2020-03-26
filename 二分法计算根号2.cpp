#include<cstdio>
#include<cmath>
int main() {
	const double eps = 1e-7;
	double left = 1.0, right = 2.0, mid;
	while (!(right - left < eps)) {
		mid = left + (right - left) / 2.0;
		if (mid * mid > 2.0)
			right = mid;
		else
			left = mid;
	}
	mid = left + (right - left) / 2.0;
	printf("%.7lf\n", mid);
	printf("%.7lf", pow(2, 0.5));
	return 0;
}