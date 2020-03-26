#include<cstdio>

int main() {
	int N;
	float need, inventory[10];
	float price[10];
	float ton_priece[10];
	scanf_s("%d%f", &N, &need);
	for (int i = 0; i < N; i++) {
		scanf_s("%f", inventory + i);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%f", price + i);
		ton_priece[i] = price[i] / inventory[i];
	}
	float total = 0.0;
	while (need) {
		int t;
		float m_price = 0.0;
		for (int i = 0; i < N; i++) {
			if (m_price < ton_priece[i] && inventory[i] != 0) {
				m_price = ton_priece[i];
				t = i;
			}
		}
		if (need > inventory[t]) {
			total += inventory[t] * m_price;
			need -= inventory[t];
			inventory[t] = 0;
		}
		else {
			total += need * m_price;
			break;
		}		
	}
	printf("%.2f", total);
	return 0;
}