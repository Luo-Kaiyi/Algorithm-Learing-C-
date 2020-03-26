#include<cstdio>
#include<cstring>
//输入12345，得到1+2+3+4+5=15，输出：one five
const int max_lens = 100;
const char spell[10][6] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

int main() {
	char num[max_lens];
	gets_s(num);
	int sum = 0;
	for (unsigned int i = 0; i < strlen(num); i++) {
		sum += num[i] - '0';
	}
	//由于0 <= sum <= 900
	if (sum >= 100)
		printf("%s %s %s", spell[sum / 100], spell[sum / 10 % 10], spell[sum % 10]);
	else if (sum >= 10)
		printf("%s %s", spell[sum / 10], spell[sum % 10]);
	else
		printf("%s", spell[sum]);
	return 0;
}