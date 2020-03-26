#include<cstdio>
#include<cstring>
#define max_lens 100

int main() {
	char str1[max_lens], str2[max_lens];
	gets_s(str1);
	gets_s(str2);
	int hashtable[128] = {};
	for (unsigned int i = 0; i < strlen(str1); i++) {
		hashtable[str1[i]]++;
	}
	bool valid = true;
	int lack = 0;
	for (unsigned int i = 0; i < strlen(str2); i++) {
		if (--hashtable[str2[i]] < 0) {
			valid = false;
			lack++;
		}
	}
	if (valid) {
		printf("Yes %d", strlen(str1) - strlen(str2));
	}
	else
		printf("No %d", lack);
	return 0;
}