#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long DeciConvert(char N[], int r) {	//将N转化为十进制数
	long long n = 0;
	int len = strlen(N);
	for (int i = 0; i < len; i++) {		
		if (N[i] >= 'a' && N[i] <= 'z')
			n = n * r + long long(N[i] - 'a' + 10);
		else
			n = n * r + long long(N[i] - '0');
	}
	return n;
}

int main() {
	char N1[10], N2[10];
	int tag, radix;
	scanf_s("%s%s%d%d", N1, 10, N2, 10, &tag, &radix);
	if (tag == 2) //tag == 2 表示N2是radix进制数，为了方便操作，交换N1与N2，保证N1是radix进制数
		swap(N1, N2);
	long long n1 = DeciConvert(N1, radix);
	int l = 2, r = 36, mid;		//二分法：从二进制到三十六进制。依次递增
	int ans = false;
	while (l <= r) {
		mid = (l + r) / 2;
		long long n2 = DeciConvert(N2, mid);
		if (n2 == n1) {
			ans = true;
			break;
		}
		else if (n2 < n1) {
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	if (ans)
		printf("%d", mid);
	else
		printf("Impossible");

	return 0;
}