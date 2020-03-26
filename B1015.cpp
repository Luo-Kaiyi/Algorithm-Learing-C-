#include<cstdio>
#include<cstring>
#include<algorithm>
#define  max_size 100

using namespace std;

struct Examinee {
	char id[10];
	int moral;
	int talent;
	int category;
};

bool cmp(Examinee a,Examinee b) {   //先按德才排序，相同再按总分由高到低排序,若总分相同按id由小到大排序
	if (a.category != b.category)
		return a.category < b.category;
	else if (a.moral + a.talent != b.moral + b.talent)
		return a.moral + a.talent > b.moral + b.talent;
	else if (a.moral != b.moral)
		return a.moral > b.moral;
	else
		return strcmp(a.id, b.id) < 0;
}
int main() {
	int N, L, H;
	Examinee  data[max_size], temp;
	scanf_s("%d%d%d", &N, &L, &H);
	//输入数据并根据德才标准划分类别
	int M = 0;			//合格的人数
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d %d", temp.id, 10, &temp.moral, &temp.talent);
		if (temp.moral >= L && temp.talent >= L) {  //当前成绩合格则记入
			data[M] = temp;
			if (temp.moral >= H && temp.talent >= H)  //德才兼备
				data[M].category = 1;
			else if(temp.moral >= H && temp.talent < H) //德胜才
				data[M].category = 2;
			else if(temp.moral >= temp.talent)   //才德均亡，但德胜才
				data[M].category = 3;
			else
				data[M].category = 4;
			M++;
		}
	}
	sort(data, data + M, cmp);
	printf("%d\n", M);
	for (int i = 0; i < M; i++) {
		printf("%s %d %d\n", data[i].id, data[i].moral, data[i].talent);
	}
	return 0;
}