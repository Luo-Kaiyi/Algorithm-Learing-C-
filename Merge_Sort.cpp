#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 100

int merge(int a[], int b[], int r[], int n, int m) {	//合并两个有序序列
	int index = 0, i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j])
			r[index++] = a[i++];
		else
			r[index++] = b[j++];
	}
	while (i < n)	r[index++] = a[i++];
	while (j < m)	r[index++] = b[j++];
	return index;
}

void merge(int A[], int L1, int R1, int L2, int R2) {
	int i = L1, j = L2;
	int index = 0;
	int temp[maxn];
	while (i <= R1 && j <= R2) {
		if (A[i] <= A[j])
			temp[index++] = A[i++];
		else
			temp[index++] = A[j++];
	}
	while (i <= R1)	temp[index++] = A[i++];
	while (j <= R2)	temp[index++] = A[j++];
	for (int t = 0; t < index; t++) {
		A[L1 + t] = temp[t];
	}
}

void MergeSort1(int A[], int left, int right) {			//归并排序的递归实现
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort1(A, left, mid);
		MergeSort1(A, mid + 1, right);
		merge(A, left, mid, mid + 1, right);
	}
}

void MergeSort2(int A[], int left, int right) {			//归并排序非递归实现
	int n = right - left + 1;		//数组中元素个数
	for (int step = 2; step / 2 < n; step *= 2) {
		for (int i = left; i <= right; i += step) {
			int mid = i + step / 2 - 1;
			if (mid + 1 <= right) {
				merge(A, i, mid, mid + 1, min(i + step - 1, right));
			}
		}	
	}	
}

void Output(int A[],int left ,int right) {
	for (int i = left; i <= right; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}

int main() {
	int A[7] = { 66,12,33,57,64,27,18 };
	int B[7] = { 66,12,33,57,64,27,18 };
	printf("Fist sort:");
	MergeSort1(A, 1, 6);
	Output(A, 1, 6);
	printf("Second sort:");
	MergeSort2(B, 1, 5);
	Output(B, 1, 5);
	return 0;
}