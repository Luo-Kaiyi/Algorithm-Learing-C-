#include<cstdio>
#include<cstring>
#include<algorithm>

int n, P[1000];
int count;
bool hashtable[1000] = { false };

void generateP(int index) {
	if (index == n + 1) {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (std::abs(i - j) == std::abs(P[i] - P[j]))	//判断两个皇后是否在对角线上
					flag = false;
			}
		}
		if (flag)
			count++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!hashtable[i]) {
			P[index] = i;
			hashtable[i] = true;
			generateP(index + 1);
			hashtable[i] = false;
		}
	}
}



int main() {
	count = 0;
	scanf_s("%d", &n);
	generateP(1);
	printf("%d", count);
	return 0;
}