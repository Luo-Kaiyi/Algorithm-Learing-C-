#include<cstdio>
#include<algorithm>
using namespace std;
//���������������ֱ�ȡ����һ������ˣ�����ܵõ������˻���
int main() {
	int N1, N2;
	int num1[100], num2[100];
	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%d", num1 + i);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%d", num2 + i);
	}
	sort(num1, num1 + N1);
	sort(num2, num2 + N2);
	int ans = 0;
	for (int i = 0; i < (N1 > N2 ? N2 : N1) && num1[i] < 0 && num2[i] < 0; i++) {		//�������ֳ˻���
		ans += num1[i] * num2[i];
	}
	for (int i = 0; N1 - 1 - i >= 0 && N2 - 1 - i >= 0 && num1[N1 - 1 - i] > 0 && num2[N2 - 1 - i] > 0; i++) {//�������ֳ˻���
		ans += num1[N1 - 1 - i] * num2[N2 - 1 - i];
	}
	printf("%d", ans);
	return 0;
}