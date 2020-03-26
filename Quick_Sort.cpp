#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int A[], int left, int right){	//ȷ����Ԫλ��,��ǰΪleft
	int pos = round(1.0 * rand() / RAND_MAX * (double(right) - double(left)) + left);			//���ѡȡһ��λ��
	int temp = A[pos];
	swap(A[pos], A[left]);		//����left��pos����ֵ
	while (left < right) {
		while (temp < A[right] && left < right)	right--;
		A[left] = A[right];
		while (temp >= A[left] && left < right) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}

void QuickSort(int A[], int left, int right) {	//��������ĵݹ�ʵ��
	if (left < right) {
		int pos = partition(A, left, right);
		QuickSort(A, left, pos - 1);
		QuickSort(A, pos + 1, right);
	}
}

int main() {
	srand((unsigned)time(NULL));		//ʹ���������time()����ϵͳʱ��
	int A[10] = { 12,10,88,65,78,15,26,47,90,11 };
	QuickSort(A, 0, 9);
	for (int i = 0; i <= 9; i++) {
		printf("%d ",A[i]);
	}
	return 0;
}