#include<cstdio>
#pragma warning(disable:4996)

int judge(char a, char b) {
	if ((a == 'S' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'S'))
		return 1;
	if ((a == 'S' && b == 'S') || (a == 'J' && b == 'J') || (a == 'B' && b == 'B'))
		return 0;
	else
		return -1;

}

int main() {
	char P1, P2;
	int num, win1 = 0, win2 = 0, draw = 0;
	int statistic[3] = { 0 };
	printf("���뽻�ִ�����\t");
	scanf_s("%d", &num);
	printf("�������˵Ľ��������ʯͷ(S)������(J)����(B)\n");

	for (int i = 0; i < num; i++) {
		getchar();
		scanf_s("%c%c",&P1, 1, &P2, 1);
		if (judge(P1, P2) == 1) {
			win1++;
			if (P1 == 'S')
				statistic[0]++;
			if (P1 == 'J')
				statistic[1]++;
			if (P1 == 'B')
				statistic[2]++;
		}
		else if (judge(P1, P2) == 0)
			draw++;
		else {
			win2++;
			if (P2 == 'S')
				statistic[0]++;
			if (P2 == 'J')
				statistic[1]++;
			if (P2 == 'B')
				statistic[2]++;
		}
	}
	printf("�׵Ļ�ʤ������%d\n�ҵĻ�ʤ������%d\nƽ�ִ�����%d\n\n", win1, win2, draw);
	printf("ʯͷ��ʤ������%d\n������ʤ������%d\n���Ļ�ʤ������%d\n", statistic[0], statistic[1], statistic[2]);

	return 0;
}