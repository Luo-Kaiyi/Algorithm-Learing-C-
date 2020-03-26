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

double ChargeCal(int s[], int e[]) {   //���뿪ʼ�ͽ���ʱ�䣬�����ʱ�䣬���ط���
	double price = 0.0;
	int time = 0;
	while (s[1] != e[1] || s[2] != e[2] || s[3] != e[3]) {   //����ʼʱ�俪ʼѭ������������ʱ��
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
	return price / 100.0;  //�����ֻ������Ԫ
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
			if (strcmp(name[j], data[i].id) == 0)   //�жϵ�ǰ�û����Ƿ��Ѿ����ֹ�
				same = 1;
		}
		if (!same)
			strcpy_s(name[user_num++], data[i].id);   //��ǰ�û���δ���ֹ�����¼���ַ�����
	}
	std::sort(data, data + N,cmp);   //��ʱ��, ����������
	printf("#######################################################\n");
	int start[4], end[4];					 //�ֱ��¼��ʼͨ���ͽ���ͨ����ʱ��
	for (int j = 0; j < user_num; j++) {
		int valid = 0;						 //��¼��ǰ�û�����Ч���ݸ���
		double charge[max_size] = { 0.0 };   //��¼��ǰ�û��ķ���
		bool call = false;					 //��ʾͨ����δ��ʼ
		for (int i = 0; i < N; i++) {
			if (strcmp(name[j], data[i].id) == 0) {
				if (strcmp(data[i].state, symbol[0]) == 0) {	//�����ʱͨ��δ��ʼ�����ҵ�ǰ��Ϣ״̬Ϊon-line
					call = true;										//��ͨ����־��Ϊtrue������¼��ʼͨ����ʱ��
					TimeRecord(data[i], start);
				}
				if (call && strcmp(data[i].state, symbol[1]) == 0) {	//�����ʱͨ���ѿ�ʼ�����ҵ�ǰ��Ϣ״̬Ϊoff-line
					TimeRecord(data[i], end);							//��¼����ͨ����ʱ��
					if(valid == 0)
						printf("%s %02d\n", name[j], start[0]); 				//��ʱ�õ�һ����Ч���ݣ��������
					printf("%02d:%02d:%02d  %02d:%02d:%02d ", start[1], start[2], start[3], end[1], end[2], end[3]);
					charge[valid] = ChargeCal(start, end);				//����˴�ͨ����ʱ��ͷ���
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