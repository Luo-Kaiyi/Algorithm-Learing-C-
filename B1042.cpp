#include<cstdio>
#include<cstring>
#define  max_lens 100

int main() {
	char str[max_lens];
	int hashtable[128] = {};
	gets_s(str);
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			hashtable[str[i] + 32]++;
		hashtable[str[i]]++;
	}
	int max_num = 0;
	char temp;
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (hashtable[str[i]] > max_num&& str[i] != ' ') {
			max_num = hashtable[str[i]];
			temp = str[i];
		}
		if (hashtable[str[i]] == max_num && str[i] != ' ' && str[i] < temp)
			temp = str[i];
	}
	printf("%c %d", temp, max_num);
	return 0;
}