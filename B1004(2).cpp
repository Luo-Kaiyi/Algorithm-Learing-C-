#include<cstdio>

#define max_size 100

struct Person {
	char name[6];
	int year, month, day;
};

bool isValid(Person p) {
	if (p.year < 1814 || p.year>2014)
		return false;
	else if (p.year == 1814) {
		if (p.month < 9)	return false;
		if (p.month == 9 && p.day < 6)	return false;
		return true;
	}
	else if (p.year == 2014) {
		if (p.month > 9)	return false;
		if (p.month == 9 && p.day > 6)	return false;
		return true;
	}
	return true;
}

bool DateCompare(Person p1, Person p2) {
	if (p1.year < p2.year)
		return true;
	if (p1.year == p2.year) {
		if (p1.month < p2.month)	return true;
		if (p1.month == p2.month && p1.day < p2.day)	return true;
		return false;
	}
	return false;
}

int main() {
	int N;
	Person data, youngest, oldest;
	int valid = 0;

	youngest.year = 1814, youngest.month = 9, youngest.day = 6;
	oldest.year = 2014, oldest.month = 9, oldest.day = 6;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d/%d/%d", &data.name, 6, &data.year, &data.month, &data.day);
		if (isValid(data)) {
			if (DateCompare(data, oldest))
				oldest = data;
			if (DateCompare(youngest, data))
				youngest = data;
			valid++;
		}
	}
	printf("%d ", valid);
	if (valid)
		printf("%s %s", oldest.name, youngest.name);
	return 0;
}