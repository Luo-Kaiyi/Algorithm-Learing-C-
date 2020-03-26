#include<cstdio>
#include<cstring>
#define max_size 100

struct Account {
	char name[11];
	char password[11];
};
int main() {
	int N;
	scanf_s("%d", &N);
	Account data[max_size];
	int modify[max_size] = {0}, mod_num = 0, m = 0;  //��¼�˺��޸ĵ����飬��Ҫ�޸ĵ��ʺŸ�����m��ʶ�޸�λ
	//�������ݣ����޸��ʺ���Ϣ
	for (int i = 0; i < N; i++) {
		scanf_s("%s %s", data[i].name, 11, data[i].password, 11);
		for (unsigned int j = 0; j < strlen(data[i].password); j++) {
			if (data[i].password[j] == '1') {
				data[i].password[j] = '@';
				m = 1;
			}	
			if (data[i].password[j] == '0') {
				data[i].password[j] = '%';
				m = 1;
			}
			if (data[i].password[j] == 'l') {
				data[i].password[j] = 'L';
				m = 1;
			}
			if (data[i].password[j] == 'O') {
				data[i].password[j] = 'o';
				m = 1;
			}
		}
		if (m) {  //����������ݱ��޸ģ����¼�������޸�λm����
			modify[mod_num++] = i;
			m = 0;
		}

	}
	if (mod_num) {
		printf("%d\n", mod_num);
		for (int i = 0; i < mod_num; i++) {
			printf("%s %s", data[modify[i]].name, data[modify[i]].password);
			if (i != mod_num - 1)
				printf("\n");
		}
	}
	else {
		if (N == 1)
			printf("There is 1 account and no account is modified.");
		else
			printf("There are %d accounts and no account is modified.", N);
	}

	return 0;
}