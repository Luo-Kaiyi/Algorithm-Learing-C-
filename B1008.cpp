#include<cstdio>
#define max_size 100

int main() {
	int lens, move;
	scanf_s("%d%d", &lens, &move);

	int array[max_size] = {};
	for (int i = 0; i < lens; i++) {
		scanf_s("%d", array + i);  //直接用数组名作为地址输入
	}

	int t;
	for (int i = lens - move - 1; i >= 0; i--) {
		t = array[i];
		array[i] = array[i + move];
		array[i + move] = t;
	}
	for (int i = 0; i < lens; i++) {
		printf("%d", array[i]);
		if (i < lens) 
			printf(" ");
	}
	return 0;
}
	/*123456
	  123654
	  125634
	  165234
	  561234
	*/