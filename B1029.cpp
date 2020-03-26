#include<cstdio>
#include<cstring>

int main() {
	char str1[20], str2[20];
	gets_s(str1);
	gets_s(str2);
	bool hashtable[128] = { false };
	for (unsigned int i = 0; i < strlen(str1); i++) {
		bool exist = false;
		if (str1[i] >= 'a' && str1[i] <= 'z')
			str1[i] = str1[i] - 'a' + 'A';
		for (unsigned int j = 0; j < strlen(str2); j++) {
			if (str2[j] >= 'a' && str2[j] <= 'z')
				str2[j] = str2[j] - 'a' + 'A';
			if (str1[i] == str2[j]) {
				exist = true;
				break;
			}
		}
		if (!exist && !hashtable[str1[i]]) {
			printf("%c", str1[i]);
			hashtable[str1[i]] = true;
		}
	}
	return 0;
}