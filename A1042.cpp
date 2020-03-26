#include<stdio.h>
//扑克牌洗牌游戏
const int N = 54;
int start[N + 1], end[N + 1], operate[N + 1];
char suit[5] = {'S', 'H', 'C', 'D', 'J'};  //分别对应梅花、红心、黑桃、方片、Joker

int main(){
	int i,num;
	printf("Enter the number of execution:\t ");
	scanf_s("%d", &num);
	//初始化牌的编号(1-54)
	for (i = 1; i <= N; i++) {
		start[i] = i;
	}
	//输入操作数组
	for (i = 1; i <= N; i++) {
		scanf_s("%d",operate + i);
	}
	//执行洗牌操作
	for (i = 0; i < num; i++) {
		for (int j = 1; j <= N; j++) 
			end[operate[j]] = start[j];	
		for (int j = 1; j <= N; j++)
			start[j] = end[j];  
	}
	//输出结果
	for (i = 1; i <= N; i++) {
		if (i != 1)
			printf(" ");
		--end[i];  //此处执行-1，是为了使花色判定准确：S(0-12)...
		printf("%c%d", suit[end[i] / 13], end[i] % 13 + 1);
	}
	return 0;
}