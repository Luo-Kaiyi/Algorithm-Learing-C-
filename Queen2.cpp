#include<cstdio>
#include<algorithm>
using namespace std;

int n, P[100];
bool hashtable[100] = {};
int t;

void generateP(int index) {
	if (index == n + 1) {
		t++;			//����ܵ������һ���Ƿ�������������
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (hashtable[x] == false) {
			bool flag = true;
			for (int i = 1; i < index; i++) {
				if (abs(i - index) == abs(P[i] - x)) {   //�ڲ���ÿһ���ʺ�λ��ʱ���ж��Ƿ������ǰĳ���ʺ���ͬһ�Խ�����
					flag = false;
					break;
				}
			}
			if (flag) {					//������Է��ڵ�x��
				P[index] = x;			//���index�еĻʺ���к�Ϊx
				hashtable[x] = true;	//��x���ѷ���
				generateP(index + 1);	//����������һ��
				hashtable[x] = false;	//һ�εݹ���ϣ���ԭ��x��δռ��
			}
		}
	}
}

int main() {
	t = 0;
	scanf_s("%d", &n);
	generateP(1);		//�ӵ�һ�п�ʼ
	printf("%d", t);
	return 0;
}