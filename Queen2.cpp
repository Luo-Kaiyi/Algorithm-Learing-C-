#include<cstdio>
#include<algorithm>
using namespace std;

int n, P[100];
bool hashtable[100] = {};
int t;

void generateP(int index) {
	if (index == n + 1) {
		t++;			//如果能到达这里，一定是符合条件的排列
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (hashtable[x] == false) {
			bool flag = true;
			for (int i = 1; i < index; i++) {
				if (abs(i - index) == abs(P[i] - x)) {   //在插入每一个皇后位置时，判断是否会与先前某个皇后在同一对角线上
					flag = false;
					break;
				}
			}
			if (flag) {					//如果可以放在第x行
				P[index] = x;			//令第index列的皇后的行号为x
				hashtable[x] = true;	//第x行已分配
				generateP(index + 1);	//继续处理下一列
				hashtable[x] = false;	//一次递归完毕，还原第x行未占用
			}
		}
	}
}

int main() {
	t = 0;
	scanf_s("%d", &n);
	generateP(1);		//从第一列开始
	printf("%d", t);
	return 0;
}