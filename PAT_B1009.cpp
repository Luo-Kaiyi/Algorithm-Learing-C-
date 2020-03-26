#include<cstdio>
#include<string.h>
#define max_size 100
int main() {
	char sentence[max_size][max_size];
	int i = 0;
	while (scanf_s("%s", sentence[i], max_size) != EOF) {
		i++;
	}
	for (; i > 0; i--) {
		printf("%s", sentence[i - 1]);
		if (i > 0)
			printf(" ");
	}
	return 0;
}