#include<cstdio>
#include<algorithm>

int main() {
	int N;
	scanf_s("%d", &N);
	int num, loc[100];
	int error = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		loc[num] = i;			//���������˳������ֵ�λ�ø�ֵ
		if (loc[num]!=num)
			error++;
	}
	int ans = 0;
	while (error > 0) {
		if (loc[0] != 0) {		
			int t = loc[0];		//��0��λ����loc[0]��λ�õĽ���
			loc[0] = loc[loc[0]];
			loc[loc[0]] = t;
			ans++;				//����������һ
			error--;			//����λ������һ
		}
		else {			//���0��λ���Ѿ���0����0������һ��λ�ô�������ֽ���
			int i = 1;
			while (i < N) {
				if (loc[i++] != i)
					break;
			}
			loc[0] = loc[i];
			loc[i] = 0;
			ans++;			//����������һ
		}
	}
	printf("%d", ans);
	return 0;
}