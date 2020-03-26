#include<cstdio>

int main() {
	int N;
	scanf_s("%d", &N);
	int team[1000] = {};
	int t_id, p_id, score;
	int best_team = -1, best_score = 0;
	while (N--) {
		scanf_s("%d-%d %d", &t_id, &p_id, &score);
		team[t_id] += score;
		if (best_score < team[t_id]) {
			best_score = team[t_id];
			best_team = t_id;
		}
	}
	printf("%d %d", best_team, best_score);
	return 0;
}