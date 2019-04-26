/*
	为了练习DFS，自己重写了"数独.cpp"
*/
#include<stdio.h>

void dfs(int index);
bool mapIsValid(int index);

int index,map[9][9];
bool allFinish;
int main() {
	while (1) {
		index = 0;
		allFinish = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (scanf("%d", &map[i][j]) == EOF) {
					return 0;
				}
			}
		}
		dfs(0);
	}
	return 0;
}

void dfs(int index) {
	if (allFinish) {
		return;
	}
	if (index == 81) {
		allFinish = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char interval[2] = {0};
				interval[0] = (j % 9 == 8) ? '\n' : ' ';
				printf("%d%s", map[i][j], interval);
			}
		}
	}

	int x = index / 9, y = index % 9;
	if (map[x][y]) {
		dfs(index + 1);
	}
	else {
		// 对每个数字进行尝试
		for (int num = 1; num <= 9; num++) {
			// 判断当前行列有无该数字，以hasThisNum标志
			bool hasThisNum = false;
			for (int i = 0; i < 9; i++) {
				if (map[x][i] == num) {
					hasThisNum = true;
					break;
				}
			}
			if (!hasThisNum) {
				for (int i = 0; i < 9; i++) {
					if (map[i][y] == num) {
						hasThisNum = true;
						break;
					}
				}
			}

			// 若有则继续尝试下一数字，若无则填充后判断全局合法性
			if (hasThisNum) {
				continue;
			}
			else {
				map[x][y] = num;
				if (mapIsValid(index)) {
					dfs(index + 1);
				}
				// 如果不合法，则将该位置重置为0后继续尝试下一数字
				map[x][y] = 0;
			}
		}
	}
}
/*
判断index所在3*3的块是否合法
*/
bool mapIsValid(int index) {
	// x,y为当前块的左上角坐标
	int x = index / 9, y = index % 9;
	x -= (x%3);
	y -= (y%3);

	int count[10] = { 0 };
	for (int i=0; i < 3; i++) {
		for (int j=0; j < 3; j++) {
			count[map[x + i][y + j]]++;
			if (count[map[x + i][y + j]] > 1 && map[x + i][y + j]) {
				return false;
			}
		}
	}
	return true;
}