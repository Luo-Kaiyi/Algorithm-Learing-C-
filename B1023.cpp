#include<cstdio>

int main() {
	int num[10];
	int counts = 0;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", num + i);
		counts++;
	}
	for (int i = 0; i < counts;) {
		if (!i) {			//�׸����֣�Ѱ�Ҳ����һ����С�ķ�����
			for (int j = 1; j < 10; j++) {
				if (num[j] > 0) {
					printf("%d", j);
					num[j]--;
					break;
				}
			}
			i++;
		}
		else {			//��������׸����֣����ǰ��������Ѱ�Ҳ����һ����ǰ����С��
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