#include<cstdio>
#include<algorithm>
using namespace std;

struct Inte {
	int left;
	int right;
};

bool cmp(Inte a, Inte b) {
	if (a.right != b.right)
		return a.right < b.right;		//先按右端点从小到大排列
	else
		return  a.left > b.left;		//再按左端点从大到小排列
}

int main() {
	Inte data[10];
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d%d", &data[i].left, &data[i].right);
	}
	sort(data, data + N,cmp);
	int ct = 1;
	int x = data[0].right;
	for (int i = 1; i < N; i++) {
		if (data[i].left >= x) {
			x = data[i].right;
			ct++;
		}
	}
	printf("%d", ct);
	return 0;
}