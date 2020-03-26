#include<cstdio>
#include<algorithm>
using namespace std;

struct Station {	//加油站信息
	double price;
	double distance;
};


bool cmp(Station a, Station b) {
	if (a.distance != b.distance)
		return a.distance < b.distance;
	else
		return a.price < b.price;
}

int main() {
	int  N;					//加油站数。
	double Cmax, D, Davg;	//油箱容量、总路程、单位油行驶距离。满油行驶距离:Cmax*Davg
	scanf_s("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
	//输入加油站信息
	Station S[500];
	for (int i = 0; i < N; i++) {
		scanf_s("%lf%lf", &S[i].price, &S[i].distance);
	}
	S[N].distance = D;		//将终点也作为一个加油站加入
	S[N].price = 0;
	sort(S, S + N + 1, cmp);	//排序：按距离由小到大

	if (S[0].distance == 0) {
		int now = 0;			//当前到达的加油站编号
		double total = 0.0;		//总费用
		double now_gas = 0.0;	//剩余油量
		while (now < N) {
			int  low_id = -1;
			double lowest = 10000.0;
			for (int i = now + 1; i <= N && S[i].distance - S[now].distance <= Cmax * Davg; i++) {	//当前可到达的加油站		
				if (lowest > S[i].price) {
					lowest = S[i].price;
					low_id = i;
					if (S[low_id].price < S[now].price) {		//如果能到更低价格的加油站终止当前循环					
						break;
					}
				}
			}
			if (low_id == -1) {			//无法到达下一个加油站,终止循环
				break;
			}
			else {
				if (S[low_id].price >= S[now].price) {		//若当前价格比能到达的加油站低，补满油
					total += S[now].price * (Cmax - now_gas);
					now_gas = Cmax - (S[low_id].distance - S[now].distance) / Davg;
					now = low_id;
				}
				else {		//如果能到更低价格的加油站
					if (now_gas < (S[low_id].distance - S[now].distance) / Davg) {  //如果当前油量小于所需油量
						total += S[now].price * ((S[low_id].distance - S[now].distance) / Davg - now_gas);
						now_gas = 0;
						now = low_id;
					}
					else
						now_gas -= (S[low_id].distance - S[now].distance) / Davg;
				}
			}
		}
		if (now == N) {
			printf("%.2lf", total);
		}
		else
			printf("The maximum distance = %.2lf", S[now].distance + Cmax * Davg);
	}
	else {
		printf("The maximum distance = 0.00");
	}
	return 0;
}