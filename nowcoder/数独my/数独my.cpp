/*
	Ϊ����ϰDFS���Լ���д��"����.cpp"
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
		// ��ÿ�����ֽ��г���
		for (int num = 1; num <= 9; num++) {
			// �жϵ�ǰ�������޸����֣���hasThisNum��־
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

			// ���������������һ���֣������������ж�ȫ�ֺϷ���
			if (hasThisNum) {
				continue;
			}
			else {
				map[x][y] = num;
				if (mapIsValid(index)) {
					dfs(index + 1);
				}
				// ������Ϸ����򽫸�λ������Ϊ0�����������һ����
				map[x][y] = 0;
			}
		}
	}
}
/*
�ж�index����3*3�Ŀ��Ƿ�Ϸ�
*/
bool mapIsValid(int index) {
	// x,yΪ��ǰ������Ͻ�����
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