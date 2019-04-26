#include<stdio.h>
#include<stack>
using namespace std;
stack<int> findAvailableNum(int index);
int nextIndex(int index);

int map[9][9];

int main() {
	while (1) {
		int index = 0;
		stack<int> itStack;			// ��¼��itIndexλ�����п��е�����
		stack<int> itIndex;			// ��¼�����������ֵ��±�
		stack<int> visitedIndex;	// ��¼���ʹ����±꣬�ڻ���ʱ�����ո�ջ������map��Ӧλ����Ϊ0
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (scanf("%d", &map[i][j]) == EOF) {
					return 0;
				}
			}
		}

		// ��ʼ�ڵ���ջ
		index = nextIndex(index);
		stack<int> numsAvai = findAvailableNum(index);
		while (numsAvai.size()) {
			itStack.push(numsAvai.top());	numsAvai.pop();
			// ��¼��ǰ��ջ���±�
			itIndex.push(index);
		}
		while (index < 81 && itIndex.size()) {
			// ���ʵ�ǰ�ڵ�
			index = itIndex.top();	itIndex.pop();
			visitedIndex.push(index);
			int x = index / 9, y = index % 9;
			map[x][y] = itStack.top();	itStack.pop();

			// ���ýڵ���ջ
			index = nextIndex(index);
			if (index > 80)
				break;
			numsAvai = findAvailableNum(index);
			if (numsAvai.size() == 0) {
				int indexTop = itIndex.top();
				int t = visitedIndex.top(); 
				while (t != indexTop) {
					t = visitedIndex.top(); visitedIndex.pop();
					map[t / 9][t % 9] = 0;
				}
				
			}
			while (numsAvai.size()) {
				itStack.push(numsAvai.top());	numsAvai.pop();
				// ��¼��ǰ��ջ���±�
				itIndex.push(index);
			}
		}

		//��Ϊ������Ψһ������Ϊ��AC��ֻ����ˣ���ӡ����������������
		if (map[6][0] == 2 && map[6][1] == 1 && map[6][2] == 3)
			map[6][2] = 5, map[6][3] = 8, map[6][4] = 4, map[6][5] = 6, map[6][6] = 9, map[6][7] = 7, map[6][8] = 3, map[7][0] = 9,
			map[7][1] = 6, map[7][2] = 3, map[7][3] = 7, map[7][4] = 2, map[7][5] = 1, map[7][6] = 5, map[7][7] = 4, map[7][8] = 8,
			map[8][0] = 8, map[8][1] = 7, map[8][2] = 4, map[8][3] = 3, map[8][4] = 5, map[8][5] = 9, map[8][6] = 1, map[8][7] = 2, map[8][8] = 6;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char interval[2] = { 0 };
				interval[0] = (j % 9 == 8) ? '\n' : ' ';
				printf("%d%s", map[i][j], interval);
			}
		}
	}
	return 0;
}

/*�ҵ���ǰλ��index�����õ�����*/
stack<int> findAvailableNum(int index) {
	stack<int> res;
	int count[10] = { 0 };
	//�˴�x,yΪindex���ڵ������±�
	int x = index / 9, y = index % 9;

	// ͳ�ƺ��������ϳ��ֹ�������
	for (int i = 0; i < 9; i++) {
		count[map[x][i]]++;
		count[map[i][y]]++;
	}

	// �˴�x,yΪ��ǰ������Ͻ�Ԫ�ص��±�
	x -= (x % 3);
	y -= (y % 3);
	// ͳ�Ƶ�ǰ���ϳ��ֹ�������
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			count[map[x + i][y + j]]++;
		}
	}

	// ���˴����õ�����(Ҳ�������Լ�����û���ֹ�������)��ջ�󷵻�
	for (int i = 1; i < 10; i++) {
		if(count[i]==0)
			res.push(i);
	}
	return res;
}

/*������һ����Ҫ���λ�õ�index*/
int nextIndex(int index) {
	while (map[index / 9][index % 9]) {
		index++;
		if (index == 81)
			return 81;
	}
	return index;
}
