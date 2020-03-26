#include<cstdio>
//计算两个日期之前的天数差（包含这两个日期在内）
//各月份天数
int month[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, 
{30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

//判断是否是闰年
bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
	int time1, y1, m1, d1;
	int time2, y2, m2, d2;
	int t, difference = 1;
	while (scanf_s("%d%d", &time1, &time2) != EOF) {
		//使第一个日期早于第二个日期
		if (time1 > time2) {
			t = time2;
			time2 = time1;
			time1 = t;
		}
		//提取年、月、日
		y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
		y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
		//计算天数差
		while (y1 != y2 || m1 != m2 || d1 != d2) {
			d1++;
			difference++;
			if (d1 > month[m1][isLeap(y1)]) {
				d1 = 1;
				m1++;
				if(m1 > 12){
					y1++;
					m1 = 1;
				}
			}
		}
		printf("The difference between these two date is %d days.", difference);
	}
	return 0;
}
