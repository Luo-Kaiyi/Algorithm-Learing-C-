#include<cstdio>
#include<cstring>
#include<algorithm>

#define max_lens 100
int main() {
	int N;
	char data[max_lens][max_lens], res[max_lens];
	unsigned int min_lens = 100;
	scanf_s("%d", &N);
	int a = getchar();			//½ÓÊÕ»»ĞĞ·û
	for (int i = 0; i < N; i++) {
		gets_s(data[i]);
		if (strlen(data[i]) < min_lens)
			min_lens = strlen(data[i]);
		std::reverse(&data[i][0], &data[i][strlen(data[i])]);  //×Ö·û´®ÄæĞò
	}
	int same, n = 0;
	for (unsigned int i = 0; i < min_lens; i++) {
		same = 1;
		for (int j = 1; j < N; j++) {
			if (data[j][i] != data[0][i])
				same = 0;
		}
		if (same) {
			res[n++] = data[0][i];
		}
	}
	if (n)
		while (n) {
			printf("%c", res[(n--) - 1]);
		}
	else
		printf("nai");
	return 0;
}