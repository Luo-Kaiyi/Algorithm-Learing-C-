#include<cstdio>

int search(int a[], int left, int right, int x) {	//��x������a�е�λ�ã����û�У�����-1
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;	//Ҳ����дΪ mid = left + (right - left) / 2; ����Խ��
		if (a[mid] == x)
			return mid;
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return -1;
}

int lower_bound(int a[], int left, int right, int x) {	//������a��x���������߽�
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] >= x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int upper_bound(int a[], int left, int right, int x) {	//������a��x���ҿ�����߽�
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}


int main() {
	const int n = 11;
	int A[n] = { 1,3,4,6,6,7,8,10,11,12,15 };
	int x;
	scanf_s("%d", &x);
	printf("%d\n[%d, %d)", search(A, 0, n - 1, x), lower_bound(A, 0, n - 1, x), upper_bound(A, 0, n - 1, x));
	return 0;
}