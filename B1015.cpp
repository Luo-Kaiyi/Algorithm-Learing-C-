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

bool cmp(Examinee a,Examinee b) {   //�Ȱ��²�������ͬ�ٰ��ܷ��ɸߵ�������,���ܷ���ͬ��id��С��������
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
	//�������ݲ����ݵ²ű�׼�������
	int M = 0;			//�ϸ������
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d %d", temp.id, 10, &temp.moral, &temp.talent);
		if (temp.moral >= L && temp.talent >= L) {  //��ǰ�ɼ��ϸ������
			data[M] = temp;
			if (temp.moral >= H && temp.talent >= H)  //�²ż汸
				data[M].category = 1;
			else if(temp.moral >= H && temp.talent < H) //��ʤ��
				data[M].category = 2;
			else if(temp.moral >= temp.talent)   //�ŵ¾���������ʤ��
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