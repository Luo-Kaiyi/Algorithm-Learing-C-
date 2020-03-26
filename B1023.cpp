#include<cstdio>

int main() {
	int num[10];
	int counts = 0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", num + i);
		counts++;
	}
	for (int i = 0; i < counts;) {
		if (!i) {			//首个数字，寻找并输出一个最小的非零数
			for (int j = 1; j < 10; j++) {
				if (num[j] > 0) {
					printf("%d", j);
					num[j]--;
					break;
				}
			}
			i++;
		}
		else {			//如果不是首个数字，则从前往后依次寻找并输出一个当前的最小数
			for (int j = 0; j < 10; j++) {
				if (num[j] > 0) {
					printf("%d", j);
					num[j]--;
					break;
				}
			}
			i++;
		}
	}
	return 0;
}