#include<cstdio>
#include<cstring>
#define max_lens 100
int main() {
	char str1[max_lens], str2[max_lens];
	gets_s(str1);
	gets_s(str2);
	int hashtable[128] = {};
	for (unsigned int i = 0; i < strlen(str2); i++) {
		hashtable[str2[i]]++;
	}
	for (unsigned int i = 0; i < strlen(str1); i++) {
		if (!hashtable[str1[i]])
			printf("%c", str1[i]);
	}
	return 0;
}