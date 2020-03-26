#include<cstdio>
#include<algorithm>

int main() {
	int N;
	scanf_s("%d", &N);
	int num, loc[100];
	int error = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		loc[num] = i;			//按照输入的顺序给数字的位置赋值
		if (loc[num]!=num)
			error++;
	}
	int ans = 0;
	while (error > 0) {
		if (loc[0] != 0) {		
			int t = loc[0];		//将0的位置与loc[0]的位置的交换
			loc[0] = loc[loc[0]];
			loc[loc[0]] = t;
			ans++;				//交换次数加一
			error--;			//错误位置数减一
		}
		else {			//如果0的位置已经是0，则将0与任意一个位置错误的数字交换
			int i = 1;
			while (i < N) {
				if (loc[i++] != i)
					break;
			}
			loc[0] = loc[i];
			loc[i] = 0;
			ans++;			//交换次数加一
		}
	}
	printf("%d", ans);
	return 0;
}