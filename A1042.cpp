#include<stdio.h>
//�˿���ϴ����Ϸ
const int N = 54;
int start[N + 1], end[N + 1], operate[N + 1];
char suit[5] = {'S', 'H', 'C', 'D', 'J'};  //�ֱ��Ӧ÷�������ġ����ҡ���Ƭ��Joker

int main(){
	int i,num;
	printf("Enter the number of execution:\t ");
	scanf_s("%d", &num);
	//��ʼ���Ƶı��(1-54)
	for (i = 1; i <= N; i++) {
		start[i] = i;
	}
	//�����������
	for (i = 1; i <= N; i++) {
		scanf_s("%d",operate + i);
	}
	//ִ��ϴ�Ʋ���
	for (i = 0; i < num; i++) {
		for (int j = 1; j <= N; j++) 
			end[operate[j]] = start[j];	
		for (int j = 1; j <= N; j++)
			start[j] = end[j];  
	}
	//������
	for (i = 1; i <= N; i++) {
		if (i != 1)
			printf(" ");
		--end[i];  //�˴�ִ��-1����Ϊ��ʹ��ɫ�ж�׼ȷ��S(0-12)...
		printf("%c%d", suit[end[i] / 13], end[i] % 13 + 1);
	}
	return 0;
}