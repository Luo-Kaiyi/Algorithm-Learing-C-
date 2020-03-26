#include<cstdio>
#include<cstring>
const char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {
	char riddle[4][60];
	for (int i = 0; i < 4; i++)
		gets_s(riddle[i]);
	int ok = 0;
	for (unsigned int i = 0; i < strlen(riddle[0]); i++) {
		if (riddle[0][i] >= 'A' && riddle[0][i] <= 'Z') 
			for (unsigned int j = 0; j < strlen(riddle[1]); j++) 
				if (riddle[0][i] == riddle[1][j]) {
					if(!ok)   //第一次找到相同大写字母，输出星期
						printf("%s ", week[riddle[0][i] - 'A']);
					else {    //第二次找到相同大写字母，输出小时
						printf("%d:", riddle[0][i] - 'A' + 10);
						break;
					}
					ok++;
				}
		if (ok == 2)
			break;
	}

	for (unsigned int i = 0; i < strlen(riddle[2]) && i < strlen(riddle[3]); i++) {
		if (riddle[2][i] == riddle[3][i] && ((riddle[2][i] >= 'a' && riddle[2][i] <= 'z') ||
			(riddle[2][i] >= 'A' && riddle[2][i] <= 'Z'))) {
			printf("%02d", i);
			break;
		}
	}

	return 0;
}