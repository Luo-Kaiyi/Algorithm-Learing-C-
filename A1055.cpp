#include<cstdio>
#include<algorithm>
#include<cstring>
#define max_size 100
using namespace std;

struct Wealthy {
	char name[10];
	int age;
	int property;
};

bool cmp(Wealthy a, Wealthy b) {
	if (a.property != b.property)
		return a.property > b.property;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name, b.name) < 0;
}

int main() {
	int N, M;   
	scanf_s("%d%d", &N, &M);

	Wealthy data[max_size];		//输入数据
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d %d", data[i].name, 10, &data[i].age, &data[i].property);
	}
	int query[max_size][3] = { 0 };		//输入查询数据
	for (int i = 0; i < M; i++) {
		scanf_s("%d%d%d", query[i], query[i] + 1, query[i] + 2);
	}
	sort(data, data + N, cmp);
	for (int temp = 0; temp < M; temp++) {
		printf("Case#%d:\n", temp + 1);
		int j = 0;
		int valid = 0;		//标识查询结果数
		while (valid < query[temp][0] && j < N) {
			if (data[j].age >= query[temp][1] && data[j].age <= query[temp][2]) {
				valid++;
				printf("%s %d %d\n", data[j].name, data[j].age, data[j].property);
			}
			j++;
		}
		if (!valid)				//若未查询到结果，输出None
			printf("None\n");
	}
	return 0;
}