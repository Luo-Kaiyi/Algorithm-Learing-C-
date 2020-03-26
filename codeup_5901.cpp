#include<cstdio>
#include<cstring>

const int max_size = 256;

//判断是否是回文串
bool isplalindrome(char str[]) {
	for (unsigned int i = 0; i < strlen(str) / 2; i++) {
		if (str[i] != str[strlen(str) - i - 1])
			return false;
	}
	return true;
}
int main() {
	char str[max_size];
	printf("Enter a string:\n");
	gets_s(str);
	if (isplalindrome(str))
		printf("Yes!\n");
	else
		printf("No!\n");
	return 0;
}