//链接：https://www.nowcoder.com/questionTerminal/67df1d7889cf4c529576383c2e647c48
//来源：牛客网

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record{
	char filename[100];
	int row;
	int count;
	int inputpos;
}Rec;

int myMin(int a, int b) {
	return a < b ? a : b;
}

int findSplit(char *s) {
	for (int i = strlen(s); i>=0; i--) {
		if (s[i] == '\\')
			return i + 1;
	}
	return 0;
}

int cmp(const void *x, const void *y) {
	Rec a = *((Rec*)x);
	Rec b = *((Rec*)y);
	int cmpres = strcmp(a.filename, b.filename);
	if (cmpres == 0) {
		return a.row - b.row;
	}
	else {
		return cmpres;
	}
}

int cmp2(const void *x, const void *y) {
	Rec a = *((Rec*)x);
	Rec b = *((Rec*)y);
	int cmpres = b.count - a.count;
	if (cmpres == 0) {
		return a.inputpos - b.inputpos;
	}
	else {
		return cmpres;
	}
}

int main() {
	Rec data[1000] = {'/0', 0, 0, 0};
	Rec res[1000];
	int datanum = 0;
	char s[100] = {'\0'};
	int r = 0;
	while (scanf("%s%d", &s, &r) != EOF) {
		strcpy(data[datanum].filename, s + findSplit(s));
		data[datanum].row = r;
		data[datanum].inputpos = datanum;
		datanum++;
	}
	// 排序
	qsort(data, datanum, sizeof(Rec), cmp);
	// 合并错误
	int resnum = 0;
	res[0] = data[0];
	for (int i = 1; i < datanum; i++) {
		if (strcmp(data[i].filename, res[resnum].filename) == 0 && data[i].row == res[resnum].row) {
			res[resnum].count++;
		}
		else
		{
			resnum++;
			res[resnum] = data[i];
		}
	}
	resnum++;

	//按照错误数量排序
	qsort(res, resnum, sizeof(Rec), cmp2);

	char filename[1000] = {};
	for (int i = 0; i < myMin(resnum, 8); i++) {
		int sl = strlen(res[i].filename);
		if (sl > 16) {
			strcpy(res[i].filename, res[i].filename + sl - 16);
		}
		printf("%s %d %d\n", res[i].filename, res[i].row, res[i].count+1);
	}


	return 0;
}


