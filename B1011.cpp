#include<cstdio>
#define max_size 100
int main() {
	int n;
	int arr[max_size][3];

	scanf_s("%d", &n);	//输入最大组数
	for (int i = 0; i < n; i++){	
		scanf_s("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i][0] + arr[i][1] > arr[i][2]) 
			printf("Case #%d: true", i + 1);
		else
			printf("Case #%d: false",i + 1);
		printf("\n");
	}

	return 0;
}