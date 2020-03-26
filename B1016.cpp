#include<stdio.h>

int main(void) {
	int A, Da, B, Db;
	scanf_s("%d%d%d%d", &A, &Da, &B, &Db);

	int Pa = 0, Pb = 0;
	while (A > 0) {
		if (A % 10 == Da) {
			Pa = Pa * 10 + Da;
		}
		A /= 10;
	}
	while (B > 0) {
		if (B % 10 == Db) {
			Pb = Pb * 10 + Db;
		}
		B /= 10;
	}
	printf("Pa + Pb : %d + %d = %d", Pa, Pb, Pa + Pb);
	return 0;
}