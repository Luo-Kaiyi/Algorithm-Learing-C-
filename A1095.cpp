#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<string>

#define max_size 20
using namespace std;

struct Cars {
	string id;
	int time[3];
	string state;
};

bool cmp(Cars a, Cars b) {
	if (a.id != b.id)
		return a.id < b.id;
	else if (a.time[0] != b.time[0])
		return a.time[0] < b.time[0];
	else if (a.time[1] != b.time[1])
		return a.time[1] < b.time[1];
	else
		return a.time[2] < b.time[2];
}

bool Tcmp(Cars a, Cars b) {
	if (a.time[0] != b.time[0])
		return a.time[0] < b.time[0];
	else if (a.time[1] != b.time[1])
		return a.time[1] < b.time[1];
	else if (a.time[2] != b.time[2])
		return a.time[2] < b.time[2];
	else
		return a.id < b.id;
}

bool IsValid(Cars a, Cars b) {
	if (a.id == b.id && a.state == "in" && b.state == "out")
		return true;
	else
		return false;
}

int TimeSub(int a[], int b[]) {  //计算时间相差b-a,例如: 08:10:20 - 06:22:50
	return  (b[2] + b[1] * 60 + b[0] * 3600) - (a[2] + a[1] * 60 + a[0] * 3600);
}

int main() {
	int N, K;	 //信息数、查询数目
	scanf_s("%d%d", &N, &K);

	Cars data[max_size], res[max_size];
	for (int i = 0; i < N; i++) {
		cin >> data[i].id;
		scanf_s("%d:%d:%d", data[i].time, data[i].time + 1, data[i].time + 2);
		cin >> data[i].state;
	}
	int query[max_size][3];
	for (int i = 0; i < K; i++) {
		scanf_s("%d:%d:%d", query[i], query[i] + 1, query[i] + 2);
	}
	sort(data, data + N, cmp);		//先按id排序，再按时间先后顺序排序
	int max_time = 0;
	string mt_id[max_size];
	int m_num = 0;
	int val_num = 0;
	for (int i = 0; i < N - 1; i++) {
		if (IsValid(data[i], data[i + 1])) {
			res[val_num++] = data[i];
			res[val_num++] = data[i+1];
			if (max_time < TimeSub(data[i].time, data[i + 1].time)) {
				max_time = TimeSub(data[i].time, data[i + 1].time);
				m_num = 0;
				mt_id[m_num] = data[i].id;
			}
			if (max_time == TimeSub(data[i].time, data[i + 1].time) && mt_id[m_num] != data[i].id) {
				mt_id[++m_num] = data[i].id;
			}
		}
	}
	sort(res, res + val_num, Tcmp);		//对有效数据按时间排序
	for (int t = 0; t < K; t++) {
		int park_num = 0;
		for (int i = 0; i < N; i++) {
			if (TimeSub(data[i].time, query[t]) < 0)
				break;
			if (data[i].state == "in")
				park_num++;
			if (data[i].state == "out")
				park_num--;
		}
		printf("%d\n", park_num);
	}
	for (int i = 0; i <= m_num; i++) {
		cout << mt_id[i] << " ";
	}
	printf("%02d:%02d:%02d", max_time / 3600, max_time / 60 % 60, max_time % 60);
	return 0;
}