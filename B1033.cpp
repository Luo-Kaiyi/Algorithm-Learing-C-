#include<cstdio>
#include<cstring>

int main() {
	char broken[10], str[20];
	gets_s(broken);
	gets_s(str);
	int len1 = strlen(broken);
	int len2 = strlen(str);
	bool hashtable[128];
	memset(hashtable, true, sizeof(hashtable));
	for (int i = 0; i < len1; i++) {
		if (broken[i] >= 'A' && broken[i] <= 'Z')
			hashtable[broken[i] + 32] = false;
		hashtable[broken[i]] = false;
	}
	bool exist = false;
	for (int i = 0; i < len2; i++) {
		if (hashtable[str[i]]) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				if (hashtable['+']) {
					printf("%c", str[i]);
					exist = true;
				}
			}
			else {
				printf("%c", str[i]);
				exist = true;
			}
		}
	}
	if (!exist)
		printf("\n");
	return 0;
}