#include<cstdio>
#define maxn 11
int p[maxn], n;
bool hashtable[maxn] = { false };
void FullP(int index) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d", p[i]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		if (!hashtable[i]) {
			p[index] = i;
			hashtable[i] = true;
			FullP(index + 1);
			hashtable[i] = false;
		}
	}
}

int main() {
	scanf_s("%d", &n);
	FullP(1);
	return 0;
}