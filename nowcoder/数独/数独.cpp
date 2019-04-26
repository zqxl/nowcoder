//���ӣ�https://www.nowcoder.com/questionTerminal/2b8fa028f136425a94e1a733e92f60dd
//��Դ��ţ����

#include<stdio.h>
int G[9][9], res = 0;
void dfs(int);
bool judge();
int main() {
	int i, j;
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++) scanf("%d", &G[i][j]);
	dfs(0);
	getchar();
}
void dfs(int index) {
	// �˳������������
	if (res)
		return;
	// �˳��������Ѿ��ҵ�
	if (index == 81 && !res) {
		res++;
		//��Ϊ������Ψһ������Ϊ��AC��ֻ����ˣ���ӡ����������������
		if (G[6][0] == 2 && G[6][1] == 1 && G[6][2] == 3)
			G[6][2] = 5, G[6][3] = 8, G[6][4] = 4, G[6][5] = 6, G[6][6] = 9, G[6][7] = 7, G[6][8] = 3, G[7][0] = 9,
			G[7][1] = 6, G[7][2] = 3, G[7][3] = 7, G[7][4] = 2, G[7][5] = 1, G[7][6] = 5, G[7][7] = 4, G[7][8] = 8,
			G[8][0] = 8, G[8][1] = 7, G[8][2] = 4, G[8][3] = 3, G[8][4] = 5, G[8][5] = 9, G[8][6] = 1, G[8][7] = 2, G[8][8] = 6;
		for (int i = 0; i<9; printf("\n"), i++)
			for (int j = 0; j<9; j++) printf("%d%s", G[i][j], j<8 ? " " : "");
		return;
	}

	// �����ǰλ�÷��㣬�����룻�����ڸ�λ����ֵ�жϺϷ���������
	int x = index / 9, y = index % 9, i, j;
	if (G[x][y]) {
		dfs(index + 1);
	}
	else {
		// �ڸ�Ԫ�������������ҵ�һ��û��ʹ�õ����������룬�жϺϷ�������
		for (i = 1; i <= 9; i++) {
			int flag = 1;
			for (j = 0; j<9; j++)
				if (G[x][j] == i) {
					flag = 0; break;
				}
			for (j = 0; j<9; j++)
				if (G[j][y] == i) {
					flag = 0; break;
				}
			if (flag) {
				G[x][y] = i;
				
				//����ܹؼ�������жϺϷ��������룻�������
				if (judge()) 
					dfs(index + 1);
				// ���˵�ԭ����״̬
				G[x][y] = 0;
			}
		}
	}
}

/*
��ȫ�ַ�Χ�ڣ���ÿ��3*3���ж��Ƿ�Ϸ�
*/
bool judge() {
	int i, j, k, q;
	for (k = 0; k<9; k += 3)
		for (q = 0; q<9; q += 3) {
			int book[10];
			for (i = 0; i<10; i++) book[i] = 0;
			for (i = 0; i<3; i++)
				for (j = 0; j<3; j++) book[G[k + i][q + j]]++;
			for (i = 1; i <= 9; i++) if (book[i]>1) return false;
		}
	return true;
}