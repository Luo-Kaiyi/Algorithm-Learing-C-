#include<cstdio>
#include<cstring>
#include<algorithm>
#define max_size 10

struct Info {
	char id[10];
	int month, day, hour, min;
	char state[10];
};

double cost[24] = { 10.0,10.0,10.0,10.0,10.0,10.0,20.0,20.0,20.0,15.0,15.0,15.0,
					15.0,15.0,15.0,15.0,20.0,30.0,20.0,15.0,15.0,10.0,10.0,10.0 };
char symbol[2][10] = { "on-line","off-line" };

bool cmp(Info a, Info b) {
	if (a.month != b.month)
		return a.month < b.month;
	else if (a.day != b.day)
		return a.day < b.day;
	else if (a.hour != b.hour)
		return a.hour < b.hour;
	else if (a.min != b.min)
		return a.min < b.min;
	else
		return strcmp(a.id, b.id) < 0;
}

void TimeRecord(Info a,int t[]) {
	t[0] = a.month;
	t[1] = a.day;
	t[2] = a.hour;
	t[3] = a.min;
}

double ChargeCal(int s[], int e[]) {   //输入开始和结束时间，输出总时间，返回费用
	double price = 0.0;
	int time = 0;
	while (s[1] != e[1] || s[2] != e[2] || s[3] != e[3]) {   //从起始时间开始循环递增到结束时间
		price += cost[s[2]];
		time++;
		s[3]++;
		if (s[3] > 59) {
			s[3] = 0;
			if (++s[2] > 23) {
				s[2] = 0;
				++s[1];
			}
		}
	}
	printf("%d", time);
	return price / 100.0;  //把美分换算成美元
}

int main() {
	Info data[max_size];
	int N;
	scanf_s("%d", &N);

	char name[max_size][10];
	int user_num = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d:%d:%d:%d %s", data[i].id, 10,
			&data[i].month, &data[i].day, &data[i].hour, &data[i].min, data[i].state, 10);
		int same = 0;
		for (int j = 0; j < user_num; j++) {
			if (strcmp(name[j], data[i].id) == 0)   //判断当前用户名是否已经出现过
				same = 1;
		}
		if (!same)
			strcpy_s(name[user_num++], data[i].id);   //当前用户名未出现过，记录入字符数组
	}
	std::sort(data, data + N,cmp);   //按时间, 对数据排序
	printf("#######################################################\n");
	int start[4], end[4];					 //分别记录开始通话和结束通话的时间
	for (int j = 0; j < user_num; j++) {
		int valid = 0;						 //记录当前用户的有效数据个数
		double charge[max_size] = { 0.0 };   //记录当前用户的费用
		bool call = false;					 //表示通话尚未开始
		for (int i = 0; i < N; i++) {
			if (strcmp(name[j], data[i].id) == 0) {
				if (strcmp(data[i].state, symbol[0]) == 0) {	//如果此时通话未开始，并且当前信息状态为on-line
					call = true;										//将通话标志置为true，并记录开始通话的时间
					TimeRecord(data[i], start);
				}
				if (call && strcmp(data[i].state, symbol[1]) == 0) {	//如果此时通话已开始，并且当前信息状态为off-line
					TimeRecord(data[i], end);							//记录结束通话的时间
					if(valid == 0)
						printf("%s %02d\n", name[j], start[0]); 				//此时得到一个有效数据，进行输出
					printf("%02d:%02d:%02d  %02d:%02d:%02d ", start[1], start[2], start[3], end[1], end[2], end[3]);
					charge[valid] = ChargeCal(start, end);				//计算此次通话的时间和费用
					printf(" $%.2lf\n", charge[valid++]);
				}
			}
		}
		if (valid) {
			double total = 0.0;
			for (int i = 0; i < valid; i++) {
				total += charge[i];
			}
			printf("Total amount:$%.2lf\n", total);
			if (j != user_num - 1)
				printf("\n");
		}
	}
	return 0;
}