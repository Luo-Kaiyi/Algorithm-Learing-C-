#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

bool cmp(string a, string b) {
	int num1 = 0, num2 = 0;
	int len1 = 0, len2 = 0;
	for (int i = 0; a[i] != '\0'; i++) {		//��aת��Ϊ����
		num1 = num1 * 10 + (a[i] - '0');
		if (!(a[i] == '0' && len1 == 0))		//��ȥ��ͷ��0������a�ĳ���
			len1++;								
	}
	for (int i = 0; b[i] != '\0'; i++) {		//��bת��Ϊ����
		num2 = num2 * 10 + (b[i] - '0');
		if (!(b[i] == '0' && len2 == 0))		//��ȥ��ͷ��0������b�ĳ���
			len2++;
	}
	return num1 * int(pow(10, len2)) + num2 < num2 * int(pow(10, len1)) + num1;
}

int main() {
	int N;
	scanf_s("%d", &N);
	string num[10];
	for (int i = 0; i < N; i++) {
		cin>>num[i];
	}
	sort(num, num + N, cmp);
	for (int i = 0; i < N; i++) {
		bool ishead = true;
		for (int j = 0; num[i][j] != '\0'; j++) {
			if (!(num[i][j] == '0' && ishead == true)) {
				printf("%c", num[i][j]);
				ishead = false;
			}
		}
	}
	return 0;
}