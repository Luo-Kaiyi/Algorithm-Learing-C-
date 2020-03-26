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
	printf("输入交手次数：\t");
	scanf_s("%d", &num);
	printf("输入两人的交手情况：石头(S)、剪刀(J)、布(B)\n");

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
	printf("甲的获胜次数：%d\n乙的获胜次数：%d\n平手次数：%d\n\n", win1, win2, draw);
	printf("石头获胜次数：%d\n剪刀获胜次数：%d\n布的获胜次数：%d\n", statistic[0], statistic[1], statistic[2]);

	return 0;
}