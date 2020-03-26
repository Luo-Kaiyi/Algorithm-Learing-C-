#include<cstdio>

struct Record {
	char id[10];
	int in_time[3];
	int out_time[3];
};
//时刻比较函数：前一个时刻比后一个晚，返回true
bool TimeCompare(int time1[], int time2[]) {
	if (time1[0] != time2[0])	return time1[0] > time2[0];
	else {
		if (time1[1] != time2[1])	return time1[1] > time2[1];
		else
			return time1[2] >= time2[2];
	}
}

int main() {
	int num;
	scanf_s("%d", &num);
	Record first, last, temp;
	first.in_time[0] = 24, first.in_time[1] = 60, first.in_time[2] = 60;
	last.out_time[0] = 0, last.out_time[1] = 0, last.out_time[2] = 0;

	for (int i = 0; i < num; i++) {
		scanf_s("%s %d:%d:%d %d:%d:%d", &temp.id, 11, &temp.in_time[0], &temp.in_time[1], &temp.in_time[2],
			&temp.out_time[0], &temp.out_time[1], &temp.out_time[2]);
		if (TimeCompare(first.in_time, temp.in_time))	//temp的进入时间比first早执行first = temp
			first = temp;
		if (TimeCompare(temp.out_time, last.out_time))	//temp的离开时间比last晚执行last = temp
			last = temp;
	}
	printf("%s %s", first.id, last.id);
	return 0;
}