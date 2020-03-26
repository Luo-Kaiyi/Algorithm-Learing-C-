#include<cstdio>
#include<cstring>
#define max_lens 100

char dict[6] = { 'P','A','T','e','s','t' };

int main() {
	char str[max_lens];
	gets_s(str);
	int hashtable[128] = {};
	int num = 0;
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't') {
			num++;
			hashtable[str[i]]++;
		}
	}
	for (int i = 0; i < num;) {
		int j = 0;
		while (j < 6) {
			if (hashtable[dict[j]]-- > 0) {
				printf("%c", dict[j]);
				i++;
			}
			j++;
		}
	}
	return 0;
}