/*
京东2018实习生招聘  C++开发工程师
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
		// 判断合法
		int differ = countx - count0;
		if (!(differ == 0 || differ == 1)) {
			printf("x\n");
			goto nextLoop;
		}

		// 如果双方子数都小于3，则无人获胜
		if (countx < 3) {
			int res = countx == count0 ? 1 : 2;
			printf("%d\n", res);
			goto nextLoop;
		}

		// 三横
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
		// 三纵
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

		// 两斜线
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

		// 判断平局
		if (countx + count0 == 9) {
			printf("draw\n");
			goto nextLoop;
		}

		// 下一轮
		res = countx == count0 ? 1 : 2;
		printf("%d\n", res);

		//下一轮循环
	nextLoop:
		;
	}
	return 0;
}


/*以上程序只通过了69%，原因是没有考虑X赢时，diff不能为0

以下是大佬c++代码

#include <iostream>
#include <string>
using namespace std;

int main()
{
while(1) {
char a[3][3]; //二维数组存储棋盘数据
int xCount = 0, oCount = 0; //X和0的个数
for(int i = 0; i < 3; ++i) {
string s = "";
getline(cin, s);
if(s.size() == 0) return 0; //终止条件
for(int j = 0; j < 3; ++j) {
a[i][j] = s[j]; //赋值
// 计数
if(s[j] == 'X') ++xCount;
else if(s[j] == '0') ++oCount;
}
}

// 计算差值和基本判断
int diff = xCount - oCount;
if(diff != 0 && diff != 1) {
cout << "x" << endl;
continue;
}

int wx = 0, wo = 0; //X赢和0赢的标志
// 判断行
for(int i = 0; i < 3; ++i) {
if(a[i][1] != '.' && a[i][0] == a[i][1] && a[i][2] == a[i][1]) {
if(a[i][1] == 'X') wx = 1;
else wo = 1;
}
}
// 判断列
for(int i = 0; i < 3; ++i) {
if(a[1][i] != '.' && a[0][i] == a[1][i] && a[2][i] == a[1][i]) {
if(a[1][i] == 'X') wx = 1;
else wo = 1;
}
}
// 判断对角
if(a[1][1] != '.' && ((a[0][0] == a[1][1] && a[2][2] == a[1][1]) || (a[0][2] == a[1][1] && a[2][0] == a[1][1]))) {
if(a[1][1] == 'X') wx = 1;
else wo = 1;
}

// 判断输出
if(wx && wo || wx && !diff || wo && diff) cout << "x" << endl; //X与0不能同时赢；X赢时diff不能为0；0赢时diff不能为1
else if(wx) cout << "1 won" << endl;
else if(wo) cout << "2 won" << endl;
else if(xCount + oCount == 9) cout << "draw" << endl;
else if(diff) cout << "2" << endl;
else if(diff == 0) cout << "1" << endl;
}
}
*/
