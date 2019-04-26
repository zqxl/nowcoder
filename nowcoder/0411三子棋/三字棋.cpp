/*
����2018ʵϰ����Ƹ  C++��������ʦ
http://exercise.acmcoder.com/quesexcuse?paperId=172
*/
#include<stdio.h>

void won(char c, int b) {
	if(!b && c=='0'){
		printf("x\n");
	}
	else {
		int res = c == 'X' ? 1 : 2;
		printf("%d won\n", res);
	}
}

int main() {
	char map[3][3];
	while (1) {
		char res = 0;
		int count0 = 0, countx = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[i][j] = getchar();
				if (map[i][j] == EOF) {
					return 0;
				}
				if (map[i][j] == '0') {
					count0++;
				}
				else if (map[i][j] == 'X') {
					countx++;
				}
			}
			getchar();
		}
		// �жϺϷ�
		int differ = countx - count0;
		if (!(differ == 0 || differ == 1)) {
			printf("x\n");
			goto nextLoop;
		}

		// ���˫��������С��3�������˻�ʤ
		if (countx < 3) {
			int res = countx == count0 ? 1 : 2;
			printf("%d\n", res);
			goto nextLoop;
		}

		// ����
		for (int i = 0; i < 3; i++) {
			if (map[i][0] != '.' && map[i][0] == map[i][1] && map[i][1] == map[i][2]) {
				if (res == 0)
					res = map[i][0];
				else {
					printf("x\n");
					goto nextLoop;
				}
			}
		}
		if (res != 0) {
			won(res, countx == count0);
			goto nextLoop;
		}
		// ����
		res = 0;
		for (int i = 0; i < 3; i++) {
			if (map[0][i] != '.' && map[0][i] == map[1][i] && map[1][i] == map[2][i]) {
				if (res == 0)
					res = map[0][i];
				else{
					printf("x\n");
					goto nextLoop;
				}
			}
		}
		if (res != 0) {
			won(res, countx==count0);
			goto nextLoop;
		}

		// ��б��
		if (map[1][1] != '.') {
			if (map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
				won(map[1][1], countx == count0);
				goto nextLoop;
			}
			if (map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
				won(map[1][1], countx == count0);
				goto nextLoop;
			}
		}

		// �ж�ƽ��
		if (countx + count0 == 9) {
			printf("draw\n");
			goto nextLoop;
		}

		// ��һ��
		res = countx == count0 ? 1 : 2;
		printf("%d\n", res);

		//��һ��ѭ��
	nextLoop:
		;
	}
	return 0;
}


/*���ϳ���ֻͨ����69%��ԭ����û�п���XӮʱ��diff����Ϊ0

�����Ǵ���c++����

#include <iostream>
#include <string>
using namespace std;

int main()
{
while(1) {
char a[3][3]; //��ά����洢��������
int xCount = 0, oCount = 0; //X��0�ĸ���
for(int i = 0; i < 3; ++i) {
string s = "";
getline(cin, s);
if(s.size() == 0) return 0; //��ֹ����
for(int j = 0; j < 3; ++j) {
a[i][j] = s[j]; //��ֵ
// ����
if(s[j] == 'X') ++xCount;
else if(s[j] == '0') ++oCount;
}
}

// �����ֵ�ͻ����ж�
int diff = xCount - oCount;
if(diff != 0 && diff != 1) {
cout << "x" << endl;
continue;
}

int wx = 0, wo = 0; //XӮ��0Ӯ�ı�־
// �ж���
for(int i = 0; i < 3; ++i) {
if(a[i][1] != '.' && a[i][0] == a[i][1] && a[i][2] == a[i][1]) {
if(a[i][1] == 'X') wx = 1;
else wo = 1;
}
}
// �ж���
for(int i = 0; i < 3; ++i) {
if(a[1][i] != '.' && a[0][i] == a[1][i] && a[2][i] == a[1][i]) {
if(a[1][i] == 'X') wx = 1;
else wo = 1;
}
}
// �ж϶Խ�
if(a[1][1] != '.' && ((a[0][0] == a[1][1] && a[2][2] == a[1][1]) || (a[0][2] == a[1][1] && a[2][0] == a[1][1]))) {
if(a[1][1] == 'X') wx = 1;
else wo = 1;
}

// �ж����
if(wx && wo || wx && !diff || wo && diff) cout << "x" << endl; //X��0����ͬʱӮ��XӮʱdiff����Ϊ0��0Ӯʱdiff����Ϊ1
else if(wx) cout << "1 won" << endl;
else if(wo) cout << "2 won" << endl;
else if(xCount + oCount == 9) cout << "draw" << endl;
else if(diff) cout << "2" << endl;
else if(diff == 0) cout << "1" << endl;
}
}
*/
